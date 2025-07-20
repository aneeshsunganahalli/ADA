#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Warshall's and Floyd's Algorithms Analysis ===\n\n");
    
    printf("Running Warshall's Algorithm Analysis...\n");
    system("gcc WarshallAlgorithm.c -o WarshallAlgorithm.exe");
    system("WarshallAlgorithm.exe");
    
    printf("\n" "Running Floyd's Algorithm Analysis...\n");
    system("gcc FloydAlgorithm.c -o FloydAlgorithm.exe");
    system("FloydAlgorithm.exe");
    
    printf("\n" "=== Algorithm Comparison Summary ===\n");
    printf("Warshall's Algorithm:\n");
    printf("- Purpose: Find transitive closure of directed graph\n");
    printf("- Time Complexity: O(V^3)\n");
    printf("- Space Complexity: O(V^2)\n");
    printf("- Output: Boolean matrix (reachability)\n");
    printf("- Use case: Connectivity analysis\n\n");
    
    printf("Floyd's Algorithm (Floyd-Warshall):\n");
    printf("- Purpose: Find all-pairs shortest paths\n");
    printf("- Time Complexity: O(V^3)\n");
    printf("- Space Complexity: O(V^2)\n");
    printf("- Output: Distance matrix (shortest path weights)\n");
    printf("- Use case: Route optimization, network analysis\n\n");
    
    printf("Data files generated:\n");
    printf("Warshall: Warshall_Sparse.txt, Warshall_Medium.txt, Warshall_Dense.txt\n");
    printf("Floyd: Floyd_Sparse.txt, Floyd_Medium.txt, Floyd_Dense.txt\n");
    
    printf("\n" "Visualization commands:\n");
    printf("gnuplot warshallcommand.gnu\n");
    printf("gnuplot floydcommand.gnu\n");
    
    printf("\n" "Graph Types Analyzed:\n");
    printf("1. Sparse: Chain-like with few random edges\n");
    printf("2. Medium: 25%% edge probability\n");
    printf("3. Dense: 50%% edge probability\n");
    
    return 0;
}
