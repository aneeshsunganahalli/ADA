#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes for all three algorithms
int euclidGCD(int a, int b, int *operations);
int consecutiveIntegerGCD(int a, int b, int *operations);
int modifiedEuclidGCD(int a, int b, int *operations);

int euclidGCD(int a, int b, int *operations) {
    *operations = 0;
    while (b != 0) {
        (*operations)++;
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int consecutiveIntegerGCD(int a, int b, int *operations) {
    *operations = 0;
    int min_val = (a < b) ? a : b;
    
    for (int t = min_val; t >= 1; t--) {
        (*operations)++;
        if (a % t == 0 && b % t == 0) {
            return t;
        }
    }
    return 1;
}

int modifiedEuclidGCD(int a, int b, int *operations) {
    *operations = 0;
    while (a != b) {
        (*operations)++;
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

void comparativeAnalysis() {
    printf("=== Comparative Analysis of GCD Algorithms ===\n\n");
    
    int test_pairs[][2] = {
        {48, 18}, {60, 24}, {35, 15}, {1071, 462}, {24, 16}, {100, 25}
    };
    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);
    
    printf("Test Cases Comparison:\n");
    printf("%-10s %-10s %-8s %-12s %-15s %-15s %-15s\n", 
           "A", "B", "GCD", "Euclid", "Consecutive", "Modified", "Best Algorithm");
    printf("%-10s %-10s %-8s %-12s %-15s %-15s %-15s\n", 
           "-----", "-----", "-----", "-------", "-----------", "--------", "--------------");
    
    for (int i = 0; i < num_tests; i++) {
        int a = test_pairs[i][0];
        int b = test_pairs[i][1];
        int ops1, ops2, ops3;
        
        int gcd1 = euclidGCD(a, b, &ops1);
        int gcd2 = consecutiveIntegerGCD(a, b, &ops2);
        int gcd3 = modifiedEuclidGCD(a, b, &ops3);
        
        // Find the best algorithm (minimum operations)
        char *best = "Euclid";
        int min_ops = ops1;
        if (ops2 < min_ops) { min_ops = ops2; best = "Consecutive"; }
        if (ops3 < min_ops) { min_ops = ops3; best = "Modified"; }
        
        printf("%-10d %-10d %-8d %-12d %-15d %-15d %-15s\n", 
               a, b, gcd1, ops1, ops2, ops3, best);
    }
    printf("\n");
}

void generateComparisonData() {
    FILE *fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\GCD_Comparison.txt", "w");
    fprintf(fp, "# Size\tEuclid\tConsecutive\tModified\n");
    
    srand(time(NULL));
    
    for (int n = 10; n <= 100; n += 10) {
        int a = n * 2;
        int b = n;
        int ops1, ops2, ops3;
        
        euclidGCD(a, b, &ops1);
        consecutiveIntegerGCD(a, b, &ops2);
        modifiedEuclidGCD(a, b, &ops3);
        
        fprintf(fp, "%d\t%d\t%d\t%d\n", n, ops1, ops2, ops3);
    }
    fclose(fp);
}

int main() {
    printf("=== GCD Algorithms Comprehensive Analysis ===\n\n");
    
    // Run individual algorithm analyses
    system("gcc EuclidAlgorithm.c -o EuclidAlgorithm.exe");
    system("EuclidAlgorithm.exe");
    
    system("gcc ConsecutiveIntegerGCD.c -o ConsecutiveIntegerGCD.exe");
    system("ConsecutiveIntegerGCD.exe");
    
    system("gcc ModifiedEuclidAlgorithm.c -o ModifiedEuclidAlgorithm.exe");
    system("ModifiedEuclidAlgorithm.exe");
    
    // Perform comparative analysis
    comparativeAnalysis();
    
    // Generate comparison data
    generateComparisonData();
    
    printf("=== Algorithm Summary ===\n");
    printf("1. Euclid's Algorithm:\n");
    printf("   - Time Complexity: O(log min(a,b))\n");
    printf("   - Most efficient for large numbers\n");
    printf("   - Uses modulo operation\n\n");
    
    printf("2. Consecutive Integer Checking:\n");
    printf("   - Time Complexity: O(min(a,b))\n");
    printf("   - Inefficient for large numbers\n");
    printf("   - Simple to understand\n\n");
    
    printf("3. Modified Euclid's Algorithm:\n");
    printf("   - Time Complexity: O(max(a,b))\n");
    printf("   - Uses subtraction instead of modulo\n");
    printf("   - Can be slow for numbers with large differences\n\n");
    
    printf("Data files generated:\n");
    printf("- Individual algorithm analyses in respective files\n");
    printf("- Comparative data: GCD_Comparison.txt\n\n");
    
    printf("Visualization commands:\n");
    printf("gnuplot euclidcommand.gnu\n");
    printf("gnuplot consecutiveintcommand.gnu\n");
    printf("gnuplot modifiedeuclidcommand.gnu\n");
    
    return 0;
}
