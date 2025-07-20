#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define INF 999999

int count;

typedef struct {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int transitiveClosure[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->adj[i][j] = 0;
            g->transitiveClosure[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
}

int warshallAlgorithm(Graph *g) {
    count = 0;
    
    // Initialize transitive closure matrix
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            count++; // Operation count for initialization
            if (i == j) {
                g->transitiveClosure[i][j] = 1; // Reflexive
            } else {
                g->transitiveClosure[i][j] = g->adj[i][j];
            }
        }
    }
    
    // Warshall's Algorithm: For each intermediate vertex k
    for (int k = 0; k < g->vertices; k++) {
        for (int i = 0; i < g->vertices; i++) {
            for (int j = 0; j < g->vertices; j++) {
                count++; // Operation count for each check
                if (g->transitiveClosure[i][k] && g->transitiveClosure[k][j]) {
                    g->transitiveClosure[i][j] = 1;
                }
            }
        }
    }
    
    return count;
}

void printTransitiveClosure(Graph *g) {
    printf("Transitive Closure Matrix:\n");
    printf("   ");
    for (int j = 0; j < g->vertices; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < g->vertices; j++) {
            printf("%2d ", g->transitiveClosure[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generateGraph(Graph *g, int vertices, int graphType) {
    initGraph(g, vertices);
    srand(time(NULL));
    
    if (graphType == 1) {
        // Sparse graph (chain-like)
        for (int i = 0; i < vertices - 1; i++) {
            addEdge(g, i, i + 1);
        }
        // Add a few random edges
        for (int i = 0; i < vertices / 4; i++) {
            int u = rand() % vertices;
            int v = rand() % vertices;
            if (u != v) addEdge(g, u, v);
        }
    } else if (graphType == 2) {
        // Medium density graph
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i != j && rand() % 4 == 0) { // 25% edge probability
                    addEdge(g, i, j);
                }
            }
        }
    } else {
        // Dense graph
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i != j && rand() % 2 == 0) { // 50% edge probability
                    addEdge(g, i, j);
                }
            }
        }
    }
}

void plotter(int graphType) {
    char *filename = graphType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Warshall_Sparse.txt" :
                     graphType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Warshall_Medium.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Warshall_Dense.txt";
    FILE *fp = fopen(filename, "w");
    
    for (int v = 5; v <= 50; v += 5) {
        Graph g;
        generateGraph(&g, v, graphType);
        int operations = warshallAlgorithm(&g);
        fprintf(fp, "%d\t%d\n", v, operations);
    }
    fclose(fp);
}

void tester() {
    printf("=== Warshall's Algorithm Tester ===\n");
    
    // Test Case 1: Simple 3-vertex directed graph
    Graph g1;
    initGraph(&g1, 3);
    addEdge(&g1, 0, 1);
    addEdge(&g1, 1, 2);
    
    printf("Test 1 - Linear chain (0->1->2):\n");
    printf("Original adjacency matrix:\n");
    printAdjacencyMatrix(&g1);
    int ops1 = warshallAlgorithm(&g1);
    printf("Transitive closure:\n");
    printTransitiveClosure(&g1);
    printf("Operations: %d\n\n", ops1);
    
    // Test Case 2: Triangle with cycle
    Graph g2;
    initGraph(&g2, 3);
    addEdge(&g2, 0, 1);
    addEdge(&g2, 1, 2);
    addEdge(&g2, 2, 0);
    
    printf("Test 2 - Cycle (0->1->2->0):\n");
    printf("Original adjacency matrix:\n");
    printAdjacencyMatrix(&g2);
    int ops2 = warshallAlgorithm(&g2);
    printf("Transitive closure:\n");
    printTransitiveClosure(&g2);
    printf("Operations: %d\n\n", ops2);
    
    // Test Case 3: Disconnected components
    Graph g3;
    initGraph(&g3, 4);
    addEdge(&g3, 0, 1);
    addEdge(&g3, 2, 3);
    
    printf("Test 3 - Disconnected (0->1, 2->3):\n");
    printf("Original adjacency matrix:\n");
    printAdjacencyMatrix(&g3);
    int ops3 = warshallAlgorithm(&g3);
    printf("Transitive closure:\n");
    printTransitiveClosure(&g3);
    printf("Operations: %d\n\n", ops3);
    
    // Test Case 4: Single vertex
    Graph g4;
    initGraph(&g4, 1);
    
    printf("Test 4 - Single vertex:\n");
    int ops4 = warshallAlgorithm(&g4);
    printf("Operations: %d\n\n", ops4);
    
    printf("=== Performance Analysis ===\n");
    printf("Time Complexity: O(V³) - Three nested loops\n");
    printf("Space Complexity: O(V²) - Adjacency and closure matrices\n");
    printf("Finds transitive closure of directed graph\n\n");
}

int main() {
    tester();
    printf("=== Warshall's Algorithm Analysis ===\n\n");
    
    // Demo with small graph
    Graph demo;
    printf("Demo with 5 vertices (Medium density):\n");
    generateGraph(&demo, 5, 2);
    
    printf("Adjacency Matrix:\n");
    printf("   ");
    for (int j = 0; j < demo.vertices; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < demo.vertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < demo.vertices; j++) {
            printf("%2d ", demo.adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int operations = warshallAlgorithm(&demo);
    printTransitiveClosure(&demo);
    printf("Operations performed: %d\n\n", operations);
    
    printf("Generating analysis data...\n");
    plotter(1); // Sparse
    plotter(2); // Medium
    plotter(3); // Dense
    
    printf("Warshall's Algorithm analysis complete.\n");
    return 0;
}
