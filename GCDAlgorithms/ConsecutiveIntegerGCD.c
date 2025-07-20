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

int main() {
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
