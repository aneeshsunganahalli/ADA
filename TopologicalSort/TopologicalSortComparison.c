#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Topological Sorting Algorithms Comparison ===\n\n");
    
    printf("Running DFS-based Topological Sort Analysis...\n");
    system("gcc DFS_TopologicalSort.c -o DFS_TopologicalSort.exe");
    system("DFS_TopologicalSort.exe");
    
    printf("\n" "Running Source Removal Topological Sort Analysis...\n");
    system("gcc SourceRemoval_TopologicalSort.c -o SourceRemoval_TopologicalSort.exe");
    system("SourceRemoval_TopologicalSort.exe");
    
    printf("\n" "=== Analysis Summary ===\n");
    printf("DFS-based approach:\n");
    printf("- Time Complexity: O(V + E)\n");
    printf("- Uses recursion and stack (implicit)\n");
    printf("- Produces reverse post-order traversal\n");
    printf("- Good for sparse graphs\n\n");
    
    printf("Source Removal approach (Kahn's Algorithm):\n");
    printf("- Time Complexity: O(V + E)\n");
    printf("- Uses queue data structure\n");
    printf("- Efficient source vertex identification using indegree\n");
    printf("- Can detect cycles easily\n");
    printf("- Good for dense graphs\n\n");
    
    printf("Data files generated:\n");
    printf("DFS: DFS_Linear.txt, DFS_Tree.txt, DFS_Dense.txt\n");
    printf("Source Removal: SourceRemoval_Linear.txt, SourceRemoval_Tree.txt, SourceRemoval_Dense.txt\n");
    
    printf("\n" "Visualization commands:\n");
    printf("gnuplot dfscommand.gnu\n");
    printf("gnuplot sourceremovalcommand.gnu\n");
    
    return 0;
}
