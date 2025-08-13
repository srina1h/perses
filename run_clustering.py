#!/usr/bin/env python3
"""
Simple wrapper script for running nuanced clustering with common configurations
"""

import sys
import argparse
from pathlib import Path
from nuanced_cluster import NuancedClusterer

def main():
    parser = argparse.ArgumentParser(description="Run nuanced clustering with preset configurations")
    parser.add_argument("findings_dir", help="Directory containing finding folders")
    parser.add_argument("output_dir", help="Output directory for clustered results")
    parser.add_argument("--preset", choices=["quick", "balanced", "thorough"], default="balanced",
                       help="Preset configuration")
    parser.add_argument("--max-per-cluster", type=int, default=5,
                       help="Maximum representatives per cluster")
    
    args = parser.parse_args()
    
    # Preset configurations
    presets = {
        "quick": {"level": 2, "max_per_cluster": 3},
        "balanced": {"level": 3, "max_per_cluster": 5},
        "thorough": {"level": 5, "max_per_cluster": 10}
    }
    
    config = presets[args.preset]
    config["max_per_cluster"] = args.max_per_cluster
    
    print(f"Running {args.preset} clustering...")
    print(f"Level: {config['level']}")
    print(f"Max per cluster: {config['max_per_cluster']}")
    
    clusterer = NuancedClusterer(args.findings_dir, args.output_dir)
    clusterer.run_clustering(level=config["level"], max_per_cluster=config["max_per_cluster"])

if __name__ == "__main__":
    main()

