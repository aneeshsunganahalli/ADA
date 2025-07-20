#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int bruteForceSearch(char *text, char *pattern, int n, int m) {
  int i, j, count = 0;
  for (i = 0; i <= n - m; i++) {
    for (j = 0; j < m; j++) {
      count++;
      if (text[i + j] != pattern[j]) break;
    }
    if (j == m) return count; // Pattern found
  }
  return count;
}

void generateText(char *text, int n, int case_type) {
  int i;
  if (case_type == 1) {
    // Worst case: text of all same characters except last
    for (i = 0; i < n - 1; i++) text[i] = 'A';
    text[n - 1] = 'B';
  } else if (case_type == 2) {
    // Best case: pattern at the beginning
    for (i = 0; i < n; i++) text[i] = 'A';
  } else {
    // Average case: random text
    for (i = 0; i < n; i++) text[i] = 'A' + (rand() % 4); // A,B,C,D
  }
  text[n] = '\0';
}

void generatePattern(char *pattern, int m, int case_type) {
  int i;
  if (case_type == 1) {
    // Worst case: pattern of all same chars as text except last
    for (i = 0; i < m - 1; i++) pattern[i] = 'A';
    pattern[m - 1] = 'B';
  } else if (case_type == 2) {
    // Best case: pattern matches from start
    for (i = 0; i < m; i++) pattern[i] = 'A';
  } else {
    // Average case: random pattern
    for (i = 0; i < m; i++) pattern[i] = 'A' + (rand() % 4);
  }
  pattern[m] = '\0';
}

void plotter(int p) {
  char *text, *pattern;
  int n, m, comparisons;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 20; n <= 1000; n += 50) {
    m = n / 4; // Pattern length is 1/4 of text length
    if (m < 2) m = 2;
    
    text = (char*)malloc((n + 1) * sizeof(char));
    pattern = (char*)malloc((m + 1) * sizeof(char));
    
    generateText(text, n, p);
    generatePattern(pattern, m, p);
    
    comparisons = bruteForceSearch(text, pattern, n, m);
    fprintf(fp, "%d\t%d\n", n, comparisons);
    
    free(text);
    free(pattern);
  }
  fclose(fp);
}

void tester() {
  printf("=== Brute Force String Matching Tester ===\n");
  
  // Test Case 1: Pattern found at beginning (Best case)
  char text1[] = "ABCDEFGHIJK";
  char pattern1[] = "ABC";
  int comp1 = bruteForceSearch(text1, pattern1, strlen(text1), strlen(pattern1));
  printf("Test 1 - Pattern at start: Text=\"%s\", Pattern=\"%s\", Comparisons=%d %s\n", 
         text1, pattern1, comp1, (comp1 == 3) ? "✓" : "✗");
  
  // Test Case 2: Pattern not found (Worst case)
  char text2[] = "AAAAAAAAAB";
  char pattern2[] = "AAB";
  int comp2 = bruteForceSearch(text2, pattern2, strlen(text2), strlen(pattern2));
  printf("Test 2 - Pattern not found: Text=\"%s\", Pattern=\"%s\", Comparisons=%d\n", 
         text2, pattern2, comp2);
  
  // Test Case 3: Pattern at end
  char text3[] = "XYZABCDEF";
  char pattern3[] = "DEF";
  int comp3 = bruteForceSearch(text3, pattern3, strlen(text3), strlen(pattern3));
  printf("Test 3 - Pattern at end: Text=\"%s\", Pattern=\"%s\", Comparisons=%d\n", 
         text3, pattern3, comp3);
  
  // Test Case 4: Multiple occurrences (finds first)
  char text4[] = "ABABACABAB";
  char pattern4[] = "ABA";
  int comp4 = bruteForceSearch(text4, pattern4, strlen(text4), strlen(pattern4));
  printf("Test 4 - Multiple patterns: Text=\"%s\", Pattern=\"%s\", Comparisons=%d %s\n", 
         text4, pattern4, comp4, (comp4 == 3) ? "✓" : "✗");
  
  // Test Case 5: Single character
  char text5[] = "HELLO";
  char pattern5[] = "L";
  int comp5 = bruteForceSearch(text5, pattern5, strlen(text5), strlen(pattern5));
  printf("Test 5 - Single char: Text=\"%s\", Pattern=\"%s\", Comparisons=%d\n", 
         text5, pattern5, comp5);
  
  // Test Case 6: Pattern longer than text
  char text6[] = "HI";
  char pattern6[] = "HELLO";
  int comp6 = bruteForceSearch(text6, pattern6, strlen(text6), strlen(pattern6));
  printf("Test 6 - Pattern > Text: Text=\"%s\", Pattern=\"%s\", Comparisons=%d %s\n", 
         text6, pattern6, comp6, (comp6 == 0) ? "✓" : "✗");
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(m) - Pattern found at beginning\n");
  printf("Worst Case: O(n*m) - Pattern not found or at end\n");
  printf("Average Case: O(n*m) - Depends on text and pattern characteristics\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1); plotter(2); plotter(3);
  printf("Brute Force String Matching analysis complete.\n");
  return 0;
}
