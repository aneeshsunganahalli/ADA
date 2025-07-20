#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int modifiedEuclidGCD(int a, int b) {
    count = 0;
    while (a != b) {
        count++; // Count each iteration
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

void plotter(int inputType) {
    char *filename = inputType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ModifiedEuclid_BestCase.txt" :
                     inputType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ModifiedEuclid_AvgCase.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ModifiedEuclid_WorstCase.txt";
    FILE *fp = fopen(filename, "w");
    srand(time(NULL));
    
    for (int n = 10; n <= 200; n += 10) { // Smaller range due to potentially many iterations
        int a, b, gcd_result;
        
        if (inputType == 1) {
            // Best case: one number is multiple of other
            a = n;
            b = n / 2;
            if (b == 0) b = 1;
        } else if (inputType == 2) {
            // Average case: random pairs with moderate difference
            a = n;
            b = n / 3 + rand() % (n / 2);
            if (b == 0) b = 1;
        } else {
            // Worst case: consecutive Fibonacci numbers
            if (n <= 2) { a = 2; b = 1; }
            else {
                int fib1 = 1, fib2 = 1, temp;
                for (int i = 3; i <= n % 15 + 5; i++) { // Use modulo to keep numbers manageable
                    temp = fib1 + fib2;
                    fib1 = fib2;
                    fib2 = temp;
                }
                a = fib2; b = fib1;
            }
        }
        
        gcd_result = modifiedEuclidGCD(a, b);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
}

void tester() {
    printf("=== Modified Euclid's Algorithm Tester ===\n");
    
    // Test cases with known results
    int testCases[][3] = {
        {12, 8, 4},     // GCD(12,8) = 4
        {15, 6, 3},     // GCD(15,6) = 3
        {21, 9, 3},     // GCD(21,9) = 3
        {10, 5, 5},     // GCD(10,5) = 5
        {7, 7, 7},      // GCD(7,7) = 7
        {13, 8, 1},     // GCD(13,8) = 1
        {6, 4, 2},      // GCD(6,4) = 2
        {25, 15, 5},    // GCD(25,15) = 5
        {1, 1, 1}       // GCD(1,1) = 1
    };
    
    int totalTests = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;
    
    for (int i = 0; i < totalTests; i++) {
        int a = testCases[i][0], b = testCases[i][1], expected = testCases[i][2];
        int result = modifiedEuclidGCD(a, b);
        char status = (result == expected) ? 'P' : 'F';
        if (result == expected) passed++;
        
        printf("Test %d: GCD(%d,%d) = %d (expected %d, ops: %d) %c\n", 
               i+1, a, b, result, expected, count, status);
    }
    
    printf("\nTest Results: %d/%d passed\n", passed, totalTests);
    printf("Efficiency Analysis:\n");
    printf("- Best case: O(log(min(a,b))) when one divides the other\n");
    printf("- Worst case: O(max(a,b)) when a,b are consecutive numbers\n");
    printf("- Average case: O(a+b) typically worse than standard Euclid\n");
    printf("- Uses subtraction instead of modulo operation\n\n");
}

int main() {
    tester();
    printf("=== Modified Euclid's Algorithm Analysis ===\n\n");
    printf("=== Modified Euclid's Algorithm Analysis ===\n\n");
    
    // Demo with sample numbers
    printf("Demo examples:\n");
    
    int pairs[][2] = {{12, 8}, {15, 6}, {21, 9}};
    for (int i = 0; i < 3; i++) {
        int a = pairs[i][0], b = pairs[i][1];
        int gcd_result = modifiedEuclidGCD(a, b);
        printf("GCD(%d, %d) = %d, Operations: %d\n", a, b, gcd_result, count);
    }
    printf("\n");
    
    printf("Generating analysis data...\n");
    plotter(1); // Best case
    plotter(2); // Average case
    plotter(3); // Worst case
    
    printf("Modified Euclid's Algorithm analysis complete.\n");
    return 0;
}
