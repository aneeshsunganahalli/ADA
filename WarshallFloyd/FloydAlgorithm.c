#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define INF 999999

int count;

typedef struct {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES][MAX_VERTICES];
} WeightedGraph;

void initGraph(WeightedGraph *g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                g->adj[i][j] = 0;
                g->dist[i][j] = 0;
            } else {
                g->adj[i][j] = INF;
                g->dist[i][j] = INF;
            }
        }
    }
}

void addEdge(WeightedGraph *g, int u, int v, int weight) {
    g->adj[u][v] = weight;
}

int floydWarshallAlgorithm(WeightedGraph *g) {
    count = 0;
    
    // Initialize distance matrix
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            count++; // Operation count for initialization
            g->dist[i][j] = g->adj[i][j];
        }
    }
    
    // Floyd-Warshall Algorithm: For each intermediate vertex k
    for (int k = 0; k < g->vertices; k++) {
        for (int i = 0; i < g->vertices; i++) {
            for (int j = 0; j < g->vertices; j++) {
                count++; // Operation count for each comparison
                if (g->dist[i][k] != INF && g->dist[k][j] != INF) {
                    if (g->dist[i][k] + g->dist[k][j] < g->dist[i][j]) {
                        g->dist[i][j] = g->dist[i][k] + g->dist[k][j];
                    }
                }
            }
        }
    }
    
    return count;
}

void tester() {
    printf("=== Floyd's Algorithm Tester ===\n");
    
    // Test Case 1: Simple 4-vertex graph
    WeightedGraph g1;
    initGraph(&g1, 4);
    addEdge(&g1, 0, 1, 5);
    addEdge(&g1, 0, 3, 10);
    addEdge(&g1, 1, 2, 3);
    addEdge(&g1, 2, 3, 1);
    
    int ops1 = floydWarshallAlgorithm(&g1);
    printf("Test 1 - 4 vertices: Operations=%d\n", ops1);
    printf("         Shortest path 0->3: %d (expected: 9)\n", g1.dist[0][3]);
    
    // Test Case 2: Disconnected components
    WeightedGraph g2;
    initGraph(&g2, 3);
    addEdge(&g2, 0, 1, 2);
    // Vertex 2 is disconnected
    
    int ops2 = floydWarshallAlgorithm(&g2);
    printf("Test 2 - Disconnected: Operations=%d\n", ops2);
    printf("         Path 0->2: %s\n", g2.dist[0][2] == INF ? "INF" : "Connected");
    
    // Test Case 3: Single vertex
    WeightedGraph g3;
    initGraph(&g3, 1);
    
    int ops3 = floydWarshallAlgorithm(&g3);
    printf("Test 3 - Single vertex: Operations=%d\n", ops3);
    
    printf("All tests completed.\n\n");
}

void generateGraph(WeightedGraph *g, int vertices) {
    initGraph(g, vertices);
    srand(time(NULL));
    
    // Add random edges with ~30% probability
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j && rand() % 100 < 30) {
                addEdge(g, i, j, (rand() % 20) + 1);
            }
        }
    }
}

void plotter() {
    FILE *fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\FloydAnalysis.txt", "w");
    
    for (int v = 5; v <= 50; v += 5) {
        WeightedGraph g;
        generateGraph(&g, v);
        fprintf(fp, "%d\t%d\n", v, floydWarshallAlgorithm(&g));
    }
    fclose(fp);
}

int main() {
    tester();
    printf("Generating analysis data...\n");
    plotter();
    printf("Floyd analysis complete.\n");
    return 0;
}
