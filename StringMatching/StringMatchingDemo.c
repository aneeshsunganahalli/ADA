#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int bruteForceSearchDetailed(char *text, char *pattern, int n, int m, int *found_at) {
  int i, j, count = 0;
  *found_at = -1;
  for (i = 0; i <= n - m; i++) {
    for (j = 0; j < m; j++) {
      count++;
      if (text[i + j] != pattern[j]) break;
    }
    if (j == m) {
      *found_at = i;
      return count; // Pattern found
    }
  }
  return count;
}

void demonstrateSearch() {
  char text[] = "ABABCABABA";
  char pattern[] = "ABABA";
  int n = strlen(text);
  int m = strlen(pattern);
  int found_at, comparisons;
  
  printf("Text: %s (length: %d)\n", text, n);
  printf("Pattern: %s (length: %d)\n", pattern, m);
  
  comparisons = bruteForceSearchDetailed(text, pattern, n, m, &found_at);
  
  if (found_at != -1) {
    printf("Pattern found at position: %d\n", found_at);
  } else {
    printf("Pattern not found\n");
  }
  printf("Total comparisons: %d\n\n", comparisons);
}

int main() {
  printf("=== Brute Force String Matching Demo ===\n");
  demonstrateSearch();
  
  printf("Generating analysis data...\n");
  system("BruteForceStringMatching.exe");
  
  return 0;
}
