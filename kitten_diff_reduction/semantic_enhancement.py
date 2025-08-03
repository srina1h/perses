"""
Semantic Enhancement for JavaScript Differential Testing Error Reduction

This module demonstrates how semantic similarity and clustering can enhance
the reduction strategies for better error grouping and deduplication.
"""

import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import DBSCAN, KMeans
from sklearn.metrics.pairwise import cosine_similarity
from sentence_transformers import SentenceTransformer
from typing import List, Dict, Tuple, Optional
import re
from finding_parser import DifferentialFinding
from error_classifier import ClassifiedError, ErrorSignature


class SemanticErrorAnalyzer:
    """Enhanced error analysis using semantic similarity and clustering."""
    
    def __init__(self, model_name: str = "all-MiniLM-L6-v2"):
        """Initialize with a sentence transformer model."""
        self.model = SentenceTransformer(model_name)
        self.tfidf_vectorizer = TfidfVectorizer(
            max_features=1000,
            stop_words='english',
            ngram_range=(1, 2)
        )
    
    def extract_semantic_features(self, findings: List[DifferentialFinding]) -> np.ndarray:
        """Extract semantic features from findings."""
        texts = []
        
        print(f"    Processing {len(findings)} findings for embeddings...")
        for i, finding in enumerate(findings):
            if i % 1000 == 0 and i > 0:
                print(f"    Processed {i}/{len(findings)} findings...")
            
            # Combine multiple text sources for semantic analysis
            text_parts = []
            
            # Add input code (normalized)
            text_parts.append(self._normalize_code(finding.input_js))
            
            # Add error messages from all engines
            for engine_output in finding.engine_outputs.values():
                if engine_output.stderr:
                    text_parts.append(engine_output.stderr)
                if engine_output.stdout:
                    text_parts.append(engine_output.stdout)
            
            # Add summary if available
            if finding.summary:
                text_parts.append(finding.summary)
            
            combined_text = " ".join(text_parts)
            texts.append(combined_text)
        
        print(f"    Generating embeddings for {len(texts)} texts...")
        # Generate embeddings
        embeddings = self.model.encode(texts)
        print(f"    Embeddings generated successfully!")
        return embeddings
    
    def cluster_findings_semantically(self, findings: List[DifferentialFinding], 
                                    eps: float = 0.3, min_samples: int = 2) -> List[List[int]]:
        """Cluster findings using semantic similarity."""
        print(f"    Starting semantic clustering with {len(findings)} findings...")
        embeddings = self.extract_semantic_features(findings)
        
        print(f"    Running DBSCAN clustering (eps={eps}, min_samples={min_samples})...")
        # Use DBSCAN for density-based clustering
        clustering = DBSCAN(eps=eps, min_samples=min_samples, metric='cosine')
        cluster_labels = clustering.fit_predict(embeddings)
        
        print(f"    Organizing clusters...")
        # Group findings by cluster
        clusters = {}
        for i, label in enumerate(cluster_labels):
            if label not in clusters:
                clusters[label] = []
            clusters[label].append(i)
        
        cluster_list = list(clusters.values())
        print(f"    Clustering complete! Found {len(cluster_list)} clusters")
        return cluster_list
    
    def find_semantic_similarities(self, findings: List[DifferentialFinding], 
                                 threshold: float = 0.8) -> List[Tuple[int, int, float]]:
        """Find semantically similar findings above a threshold."""
        print(f"    Computing semantic similarities for {len(findings)} findings...")
        embeddings = self.extract_semantic_features(findings)
        
        print(f"    Computing cosine similarity matrix...")
        similarities = cosine_similarity(embeddings)
        
        print(f"    Finding similar pairs (threshold={threshold})...")
        similar_pairs = []
        total_pairs = len(findings) * (len(findings) - 1) // 2
        processed_pairs = 0
        
        for i in range(len(findings)):
            for j in range(i + 1, len(findings)):
                similarity = similarities[i][j]
                if similarity >= threshold:
                    similar_pairs.append((i, j, similarity))
                
                processed_pairs += 1
                if processed_pairs % 100000 == 0:
                    print(f"    Processed {processed_pairs}/{total_pairs} pairs...")
        
        print(f"    Found {len(similar_pairs)} similar pairs")
        return sorted(similar_pairs, key=lambda x: x[2], reverse=True)
    
    def _normalize_code(self, code: str) -> str:
        """Normalize code for semantic analysis."""
        # Remove comments and extra whitespace
        lines = code.split('\n')
        normalized_lines = []
        
        for line in lines:
            # Remove comments
            if '//' in line:
                line = line.split('//')[0]
            
            # Remove extra whitespace
            line = re.sub(r'\s+', ' ', line.strip())
            
            if line:
                normalized_lines.append(line)
        
        return " ".join(normalized_lines)


class EnhancedErrorClassifier:
    """Enhanced error classifier using semantic analysis."""
    
    def __init__(self):
        self.semantic_analyzer = SemanticErrorAnalyzer()
        self.tfidf_vectorizer = TfidfVectorizer(
            max_features=500,
            stop_words='english',
            ngram_range=(1, 3)
        )
    
    def classify_with_semantic_similarity(self, findings: List[DifferentialFinding]) -> List[ClassifiedError]:
        """Classify findings using both pattern matching and semantic similarity."""
        print("  Step 1/3: Basic pattern-based classification...")
        # First, do basic classification
        from error_classifier import ErrorClassifier
        basic_classifier = ErrorClassifier()
        classified_errors = basic_classifier.classify_findings(findings)
        
        print("  Step 2/3: Generating semantic embeddings...")
        # Then, enhance with semantic analysis
        enhanced_errors = self._enhance_with_semantic_analysis(findings, classified_errors)
        
        print("  Step 3/3: Semantic classification complete!")
        return enhanced_errors
    
    def _enhance_with_semantic_analysis(self, findings: List[DifferentialFinding], 
                                      classified_errors: List[ClassifiedError]) -> List[ClassifiedError]:
        """Enhance classification with semantic analysis."""
        # Extract semantic features
        embeddings = self.semantic_analyzer.extract_semantic_features(findings)
        
        # Find semantic clusters
        clusters = self.semantic_analyzer.cluster_findings_semantically(findings)
        
        # Enhance each classified error with semantic information
        for i, error in enumerate(classified_errors):
            # Find which cluster this error belongs to
            cluster_id = self._find_cluster_for_finding(i, clusters)
            
            # Calculate semantic confidence
            semantic_confidence = self._calculate_semantic_confidence(
                embeddings[i], embeddings, cluster_id, clusters
            )
            
            # Update confidence with semantic information
            error.confidence = (error.confidence + semantic_confidence) / 2
            
            # Add semantic metadata
            if not hasattr(error, 'semantic_metadata'):
                error.semantic_metadata = {}
            error.semantic_metadata['cluster_id'] = cluster_id
            error.semantic_metadata['semantic_confidence'] = semantic_confidence
        
        return classified_errors
    
    def _find_cluster_for_finding(self, finding_index: int, clusters: List[List[int]]) -> int:
        """Find which cluster a finding belongs to."""
        for cluster_id, cluster in enumerate(clusters):
            if finding_index in cluster:
                return cluster_id
        return -1  # No cluster found
    
    def _calculate_semantic_confidence(self, embedding: np.ndarray, all_embeddings: np.ndarray,
                                     cluster_id: int, clusters: List[List[int]]) -> float:
        """Calculate semantic confidence based on cluster cohesion."""
        if cluster_id == -1:
            return 0.5  # Default confidence for unclustered items
        
        cluster_indices = clusters[cluster_id]
        if len(cluster_indices) == 1:
            return 0.8  # Single item in cluster
        
        # Calculate average similarity within cluster
        cluster_embeddings = all_embeddings[cluster_indices]
        similarities = cosine_similarity([embedding], cluster_embeddings)[0]
        avg_similarity = np.mean(similarities)
        
        return min(avg_similarity, 1.0)


class SemanticReducer:
    """Enhanced reducer using semantic analysis for better grouping."""
    
    def __init__(self):
        self.semantic_analyzer = SemanticErrorAnalyzer()
    
    def reduce_with_semantic_grouping(self, findings: List[DifferentialFinding], 
                                    similarity_threshold: float = 0.8) -> Dict:
        """Reduce findings using semantic grouping."""
        # Find semantic similarities
        similar_pairs = self.semantic_analyzer.find_semantic_similarities(
            findings, similarity_threshold
        )
        
        # Group findings by semantic similarity
        groups = self._create_semantic_groups(findings, similar_pairs)
        
        # Select representatives from each group
        representatives = self._select_representatives(findings, groups)
        
        return {
            'groups': groups,
            'representatives': representatives,
            'similarity_pairs': similar_pairs,
            'reduction_ratio': len(representatives) / len(findings)
        }
    
    def _create_semantic_groups(self, findings: List[DifferentialFinding], 
                              similar_pairs: List[Tuple[int, int, float]]) -> List[List[int]]:
        """Create groups based on semantic similarity."""
        # Use union-find to create connected components
        parent = list(range(len(findings)))
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            parent[find(x)] = find(y)
        
        # Union similar pairs
        for i, j, similarity in similar_pairs:
            union(i, j)
        
        # Group by root
        groups = {}
        for i in range(len(findings)):
            root = find(i)
            if root not in groups:
                groups[root] = []
            groups[root].append(i)
        
        return list(groups.values())
    
    def _select_representatives(self, findings: List[DifferentialFinding], 
                              groups: List[List[int]]) -> List[int]:
        """Select representative findings from each group."""
        representatives = []
        
        for group in groups:
            if len(group) == 1:
                representatives.append(group[0])
            else:
                # Select the finding with the smallest input size as representative
                representative = min(group, key=lambda i: len(findings[i].input_js))
                representatives.append(representative)
        
        return representatives


def demonstrate_semantic_enhancement():
    """Demonstrate how semantic similarity enhances reduction."""
    print("=== Semantic Enhancement Demonstration ===")
    
    # Create sample findings (in practice, these would come from your actual data)
    from finding_parser import DifferentialFinding, EngineOutput
    from pathlib import Path
    
    # Sample findings with similar semantic patterns
    sample_findings = [
        # Finding 1: Type coercion issue
        DifferentialFinding(
            finding_path=Path("/tmp/finding1"),
            input_js="var x = 1; var y = '2'; console.log(x + y);",
            seed_js="",
            engine_outputs={
                "engine_graaljs": EngineOutput("graaljs", "", 0, "12", ""),
                "engine_hermes": EngineOutput("hermes", "", 0, "3", ""),
                "engine_v8": EngineOutput("v8", "", 0, "12", "")
            },
            discrepancy_type=None,
            summary="Type coercion difference",
            differential_results="",
            metadata={}
        ),
        # Finding 2: Similar type coercion issue
        DifferentialFinding(
            finding_path=Path("/tmp/finding2"),
            input_js="let a = 5; let b = '10'; console.log(a + b);",
            seed_js="",
            engine_outputs={
                "engine_graaljs": EngineOutput("graaljs", "", 0, "510", ""),
                "engine_hermes": EngineOutput("hermes", "", 0, "15", ""),
                "engine_v8": EngineOutput("v8", "", 0, "510", "")
            },
            discrepancy_type=None,
            summary="Type coercion difference",
            differential_results="",
            metadata={}
        )
    ]
    
    # Demonstrate semantic analysis
    semantic_analyzer = SemanticErrorAnalyzer()
    
    print(f"Analyzing {len(sample_findings)} findings...")
    
    # Find semantic similarities
    similarities = semantic_analyzer.find_semantic_similarities(sample_findings, threshold=0.7)
    print(f"Found {len(similarities)} similar pairs:")
    for i, j, similarity in similarities:
        print(f"  Finding {i} and {j}: {similarity:.3f} similarity")
    
    # Cluster findings
    clusters = semantic_analyzer.cluster_findings_semantically(sample_findings)
    print(f"Found {len(clusters)} semantic clusters:")
    for i, cluster in enumerate(clusters):
        print(f"  Cluster {i}: {len(cluster)} findings")
    
    # Demonstrate semantic reduction
    semantic_reducer = SemanticReducer()
    reduction_result = semantic_reducer.reduce_with_semantic_grouping(sample_findings)
    
    print(f"Reduction ratio: {reduction_result['reduction_ratio']:.2%}")
    print(f"Representatives: {reduction_result['representatives']}")


if __name__ == "__main__":
    demonstrate_semantic_enhancement() 