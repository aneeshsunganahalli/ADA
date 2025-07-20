#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define INF 999999

int count;

typedef stru    fclose(fp);
}

void tester() {
    printf("=== Floyd-Warshall Algorithm Tester ===\n");
    
    // Test Case 1: Simple triangle with weights
    WeightedGraph g1;
    initGraph(&g1, 3);
    addEdge(&g1, 0, 1, 4);
    addEdge(&g1, 0, 2, 8);
    addEdge(&g1, 1, 2, 2);
    
    printf("Test 1 - Triangle (0->1:4, 0->2:8, 1->2:2):\n");
    printf("Original distance matrix:\n");
    printDistanceMatrix(&g1);
    int ops1 = floydWarshallAlgorithm(&g1);
    printf("All-pairs shortest distances:\n");
    printShortestDistances(&g1);
    printf("Operations: %d\n\n", ops1);
    
    // Test Case 2: Square with negative edge
    WeightedGraph g2;
    initGraph(&g2, 4);
    addEdge(&g2, 0, 1, 5);
    addEdge(&g2, 1, 2, -3);
    addEdge(&g2, 2, 3, 2);
    addEdge(&g2, 3, 0, 1);
    
    printf("Test 2 - Square with negative edge:\n");
    printf("Original distance matrix:\n");
    printDistanceMatrix(&g2);
    int ops2 = floydWarshallAlgorithm(&g2);
    printf("All-pairs shortest distances:\n");
    printShortestDistances(&g2);
    printf("Operations: %d\n\n", ops2);
    
    // Test Case 3: Disconnected graph
    WeightedGraph g3;
    initGraph(&g3, 4);
    addEdge(&g3, 0, 1, 3);
    addEdge(&g3, 2, 3, 7);
    
    printf("Test 3 - Disconnected (0->1:3, 2->3:7):\n");
    printf("Original distance matrix:\n");
    printDistanceMatrix(&g3);
    int ops3 = floydWarshallAlgorithm(&g3);
    printf("All-pairs shortest distances:\n");
    printShortestDistances(&g3);
    printf("Operations: %d\n\n", ops3);
    
    // Test Case 4: Single vertex
    WeightedGraph g4;
    initGraph(&g4, 1);
    
    printf("Test 4 - Single vertex:\n");
    int ops4 = floydWarshallAlgorithm(&g4);
    printf("Operations: %d\n\n", ops4);
    
    printf("=== Performance Analysis ===\n");
    printf("Time Complexity: O(V³) - Three nested loops\n");
    printf("Space Complexity: O(V²) - Distance matrix\n");
    printf("Finds all-pairs shortest paths in weighted graph\n");
    printf("Handles negative edges but not negative cycles\n\n");
}

int main() {
    tester();
    printf("=== Floyd-Warshall Algorithm Analysis ===\n\n");
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

void printShortestPaths(WeightedGraph *g) {
    printf("All-Pairs Shortest Path Matrix:\n");
    printf("     ");
    for (int j = 0; j < g->vertices; j++) {
        printf("%4d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < g->vertices; j++) {
            if (g->dist[i][j] == INF) {
                printf(" INF ");
            } else {
                printf("%4d ", g->dist[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void generateWeightedGraph(WeightedGraph *g, int vertices, int graphType) {
    initGraph(g, vertices);
    srand(time(NULL));
    
    if (graphType == 1) {
        // Sparse graph (chain-like with some random edges)
        for (int i = 0; i < vertices - 1; i++) {
            int weight = (rand() % 10) + 1; // Random weight 1-10
            addEdge(g, i, i + 1, weight);
        }
        // Add a few random edges
        for (int i = 0; i < vertices / 4; i++) {
            int u = rand() % vertices;
            int v = rand() % vertices;
            int weight = (rand() % 15) + 1;
            if (u != v) addEdge(g, u, v, weight);
        }
    } else if (graphType == 2) {
        // Medium density graph
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i != j && rand() % 4 == 0) { // 25% edge probability
                    int weight = (rand() % 20) + 1;
                    addEdge(g, i, j, weight);
                }
            }
        }
    } else {
        // Dense graph
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i != j && rand() % 2 == 0) { // 50% edge probability
                    int weight = (rand() % 25) + 1;
                    addEdge(g, i, j, weight);
                }
            }
        }
    }
}

void plotter(int graphType) {
    char *filename = graphType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Floyd_Sparse.txt" :
                     graphType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Floyd_Medium.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\WarshallFloyd\\Floyd_Dense.txt";
    FILE *fp = fopen(filename, "w");
    
    for (int v = 5; v <= 50; v += 5) {
        WeightedGraph g;
        generateWeightedGraph(&g, v, graphType);
        int operations = floydWarshallAlgorithm(&g);
        fprintf(fp, "%d\t%d\n", v, operations);
    }
    fclose(fp);
}

int main() {
    printf("=== Floyd's Algorithm Analysis ===\n\n");
    
    // Demo with small graph
    WeightedGraph demo;
    printf("Demo with 5 vertices (Medium density):\n");
    generateWeightedGraph(&demo, 5, 2);
    
    printf("Weighted Adjacency Matrix:\n");
    printf("     ");
    for (int j = 0; j < demo.vertices; j++) {
        printf("%4d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < demo.vertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < demo.vertices; j++) {
            if (demo.adj[i][j] == INF) {
                printf(" INF ");
            } else {
                printf("%4d ", demo.adj[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    int operations = floydWarshallAlgorithm(&demo);
    printShortestPaths(&demo);
    printf("Operations performed: %d\n\n", operations);
    
    printf("Generating analysis data...\n");
    plotter(1); // Sparse
    plotter(2); // Medium
    plotter(3); // Dense
    
    printf("Floyd's Algorithm analysis complete.\n");
    return 0;
}
