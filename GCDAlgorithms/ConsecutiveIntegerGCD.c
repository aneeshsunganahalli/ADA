#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int consecutiveIntegerGCD(int a, int b) {
    count = 0;
    int min_val = (a < b) ? a : b;
    
    for (int t = min_val; t >= 1; t--) {
        count++; // Count each division check
        if (a % t == 0 && b % t == 0) {
            return t;
        }
    }
    return 1; // This should never be reached for valid inputs
}

void plotter(int inputType) {
    char *filename = inputType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ConsecutiveInt_Small.txt" :
                     inputType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ConsecutiveInt_Medium.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ConsecutiveInt_Large.txt";
    FILE *fp = fopen(filename, "w");
    srand(time(NULL));
    
    int max_range = (inputType == 1) ? 50 : (inputType == 2) ? 200 : 500;
    
    for (int n = 10; n <= max_range; n += 10) {
        int a, b, gcd_result;
        
        if (inputType == 1) {
            // Small numbers - coprime pairs
            a = n;
            b = n + 1;
        } else if (inputType == 2) {
            // Medium numbers - some common factors
            a = n * 2;
            b = n * 3;
        } else {
            // Large numbers - random pairs
            a = rand() % n + 1;
            b = rand() % n + 1;
        }
        
        gcd_result = consecutiveIntegerGCD(a, b);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
}

void tester() {
    printf("=== Consecutive Integer GCD Tester ===\n");
    
    // Test cases with known results
    int testCases[][3] = {
        {12, 8, 4},     // GCD(12,8) = 4
        {15, 10, 5},    // GCD(15,10) = 5
        {21, 14, 7},    // GCD(21,14) = 7
        {17, 13, 1},    // GCD(17,13) = 1 (coprime)
        {24, 16, 8},    // GCD(24,16) = 8
        {9, 6, 3},      // GCD(9,6) = 3
        {1, 1, 1},      // GCD(1,1) = 1
        {7, 7, 7},      // GCD(7,7) = 7
        {100, 25, 25}   // GCD(100,25) = 25
    };
    
    int totalTests = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;
    
    for (int i = 0; i < totalTests; i++) {
        int a = testCases[i][0], b = testCases[i][1], expected = testCases[i][2];
        int result = consecutiveIntegerGCD(a, b);
        char status = (result == expected) ? 'P' : 'F';
        if (result == expected) passed++;
        
        printf("Test %d: GCD(%d,%d) = %d (expected %d, ops: %d) %c\n", 
               i+1, a, b, result, expected, count, status);
    }
    
    printf("\nTest Results: %d/%d passed\n", passed, totalTests);
    printf("Efficiency Analysis:\n");
    printf("- Best case: O(1) when GCD = min(a,b)\n");
    printf("- Worst case: O(min(a,b)) when GCD = 1\n");
    printf("- Average case: O(min(a,b)/2) on average\n");
    printf("- This algorithm is inefficient for large numbers!\n\n");
}

int main() {
    tester();
    printf("=== Consecutive Integer Checking Algorithm Analysis ===\n\n");
    printf("=== Consecutive Integer Checking Algorithm Analysis ===\n\n");
    
    // Demo with sample numbers
    printf("Demo examples:\n");
    
    int pairs[][2] = {{12, 8}, {15, 10}, {21, 14}};
    for (int i = 0; i < 3; i++) {
        int a = pairs[i][0], b = pairs[i][1];
        int gcd_result = consecutiveIntegerGCD(a, b);
        printf("GCD(%d, %d) = %d, Operations: %d\n", a, b, gcd_result, count);
    }
    printf("\n");
    
    printf("Generating analysis data...\n");
    plotter(1); // Small numbers
    plotter(2); // Medium numbers
    plotter(3); // Large numbers
    
    printf("Consecutive Integer Checking analysis complete.\n");
    return 0;
}
