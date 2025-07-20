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
