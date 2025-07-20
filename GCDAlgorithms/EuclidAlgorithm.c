#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int euclidGCD(int a, int b) {
    count = 0;
    while (b != 0) {
        count++; // Count each iteration
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void plotter(int inputType) {
    char *filename = inputType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\Euclid_Consecutive.txt" :
                     inputType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\Euclid_RandomPairs.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\Euclid_WorstCase.txt";
    FILE *fp = fopen(filename, "w");
    srand(time(NULL));
    
    for (int n = 10; n <= 1000; n += 50) {
        int a, b, gcd_result;
        
        if (inputType == 1) {
            // Consecutive numbers (usually GCD = 1)
            a = n;
            b = n + 1;
        } else if (inputType == 2) {
            // Random pairs
            a = rand() % n + 1;
            b = rand() % n + 1;
            if (a < b) { int temp = a; a = b; b = temp; } // Ensure a >= b
        } else {
            // Worst case: Fibonacci numbers (maximum iterations)
            if (n <= 2) { a = 2; b = 1; }
            else {
                int fib1 = 1, fib2 = 1, temp;
                for (int i = 3; i <= n % 20 + 10; i++) { // Use modulo to keep numbers manageable
                    temp = fib1 + fib2;
                    fib1 = fib2;
                    fib2 = temp;
                }
                a = fib2; b = fib1;
            }
        }
        
        gcd_result = euclidGCD(a, b);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
}

int main() {
    printf("=== Euclid's Algorithm Analysis ===\n\n");
    
    // Demo with sample numbers
    printf("Demo examples:\n");
    
    int pairs[][2] = {{48, 18}, {60, 24}, {1071, 462}};
    for (int i = 0; i < 3; i++) {
        int a = pairs[i][0], b = pairs[i][1];
        int gcd_result = euclidGCD(a, b);
        printf("GCD(%d, %d) = %d, Operations: %d\n", a, b, gcd_result, count);
    }
    printf("\n");
    
    printf("Generating analysis data...\n");
    plotter(1); // Consecutive numbers
    plotter(2); // Random pairs
    plotter(3); // Worst case (Fibonacci)
    
    printf("Euclid's Algorithm analysis complete.\n");
    return 0;
}
