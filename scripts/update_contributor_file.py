#!/usr/bin/env python3

import subprocess
import re

def get_git_contributors(repo_path="."):
    """
    Generates a list of contributors to a git project, mapping different names
    to a single contributor and counting the number of commits per user.

    Args:
        repo_path (str): The path to the git repository.

    Returns:
        dict: A dictionary mapping contributor names to their commit counts.
    """
    try:
        # Get all commit logs using git log
        result = subprocess.run(
            ["git", "log", "--pretty=%an"],
            cwd=repo_path,
            capture_output=True,
            text=True,
            check=True,
        )
        commit_authors = result.stdout.strip().split("\n")

        # Create a dictionary to map aliases to canonical names
        alias_map = {}
        contributor_counts = {}

        for author in commit_authors:
            # Normalize author names (lowercase, remove extra spaces) to improve matching
            normalized_author = re.sub(r'\s+', ' ', author.strip()).lower()

            # Check if an alias exists
            canonical_name = alias_map.get(normalized_author)

            if canonical_name:
                # If an alias exists, use the canonical name
                contributor = canonical_name
            else:
                # Otherwise, check if a similar name exists (case-insensitive)
                found_match = False
                for existing_contributor in contributor_counts:
                    if normalized_author == re.sub(r'\s+', ' ', existing_contributor.strip()).lower():
                        contributor = existing_contributor
                        alias_map[normalized_author] = contributor
                        found_match = True
                        break

                if not found_match:
                    # If no match, add the current author as a new contributor
                    contributor = author
                    alias_map[normalized_author] = contributor

            # Increment commit count
            contributor_counts[contributor] = contributor_counts.get(contributor, 0) + 1

        # Sort contributors alphabetically
        sorted_contributors = dict(sorted(contributor_counts.items()))

        return sorted_contributors

    except subprocess.CalledProcessError as e:
        print(f"Error executing git command: {e}")
        return None
    except FileNotFoundError:
        print(f"Git not found. Ensure git is installed and in your PATH.")
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None

if __name__ == "__main__":
    contributors = get_git_contributors()
    if contributors:
        print("Contributors:")
        for contributor, count in contributors.items():
            print(f"- {contributor}: {count} commits")