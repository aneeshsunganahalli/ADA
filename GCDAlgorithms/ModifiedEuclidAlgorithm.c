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

int main() {
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
