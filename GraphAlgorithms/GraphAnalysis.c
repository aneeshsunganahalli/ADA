#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Graph Algorithms Analysis ===\n\n");
    
    printf("Running DFS Analysis...\n");
    system("gcc DFS.c -o DFS.exe");
    system("DFS.exe");
    
    printf("\n" "Running BFS Analysis...\n");
    system("gcc BFS.c -o BFS.exe");
    system("BFS.exe");
    
    printf("\n" "Analysis complete. Data files generated:\n");
    printf("DFS: DFS_ConnectedWithCycle.txt, DFS_ConnectedNoCycle.txt, DFS_Disconnected.txt\n");
    printf("BFS: BFS_ConnectedWithCycle.txt, BFS_ConnectedNoCycle.txt, BFS_Disconnected.txt\n");
    
    printf("\n" "Use gnuplot commands:\n");
    printf("gnuplot dfscommand.gnu\n");
    printf("gnuplot bfscommand.gnu\n");
    
    return 0;
}
