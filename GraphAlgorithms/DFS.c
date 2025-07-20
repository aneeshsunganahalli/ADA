#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100

int count;
bool visited[MAX_VERTICES];
int componentId[MAX_VERTICES];
int currentComponent;

typedef struct {
    int vertices;
    int edges;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int v) {
    g->vertices = v;
    g->edges = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; // Undirected graph
    g->edges++;
}

bool dfs(Graph *g, int v, int parent) {
    count++;
    visited[v] = true;
    componentId[v] = currentComponent;
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[v][i]) {
            if (!visited[i]) {
                if (dfs(g, i, v)) return true; // Cycle found
            } else if (i != parent) {
                return true; // Back edge found - cycle detected
            }
        }
    }
    return false;
}

int checkConnectivityAndCycles(Graph *g) {
    count = 0;
    int components = 0;
    bool hasCycle = false;
    
    for (int i = 0; i < g->vertices; i++) {
        visited[i] = false;
        componentId[i] = -1;
    }
    
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            currentComponent = components;
            if (dfs(g, i, -1)) hasCycle = true;
            components++;
        }
    }
    
    printf("DFS Analysis:\n");
    printf("Connected Components: %d\n", components);
    printf("Graph is %s\n", (components == 1) ? "Connected" : "Not Connected");
    printf("Graph %s cycles\n", hasCycle ? "has" : "has no");
    
    if (components > 1) {
        printf("Component details:\n");
        for (int comp = 0; comp < components; comp++) {
            printf("Component %d: ", comp);
            for (int i = 0; i < g->vertices; i++) {
                if (componentId[i] == comp) printf("%d ", i);
            }
            printf("\n");
        }
    }
    printf("DFS Operations: %d\n\n", count);
    
    return count;
}

void generateGraph(Graph *g, int vertices, int graphType) {
    initGraph(g, vertices);
    srand(time(NULL));
    
    if (graphType == 1) {
        // Connected graph with cycle
        for (int i = 0; i < vertices - 1; i++) {
            addEdge(g, i, i + 1);
        }
        addEdge(g, vertices - 1, 0); // Create cycle
        
        // Add some random edges
        int extraEdges = vertices / 3;
        for (int i = 0; i < extraEdges; i++) {
            int u = rand() % vertices;
            int v = rand() % vertices;
            if (u != v && !g->adj[u][v]) {
                addEdge(g, u, v);
            }
        }
    } else if (graphType == 2) {
        // Connected graph without cycle (tree)
        for (int i = 0; i < vertices - 1; i++) {
            addEdge(g, i, i + 1);
        }
    } else {
        // Disconnected graph with multiple components
        int component1Size = vertices / 3;
        int component2Size = vertices / 3;
        
        // Component 1
        for (int i = 0; i < component1Size - 1; i++) {
            addEdge(g, i, i + 1);
        }
        
        // Component 2
        for (int i = component1Size; i < component1Size + component2Size - 1; i++) {
            addEdge(g, i, i + 1);
        }
        
        // Isolated vertices form individual components
    }
}

void plotter(int graphType) {
    char *filename = graphType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\DFS_ConnectedWithCycle.txt" :
                     graphType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\DFS_ConnectedNoCycle.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\DFS_Disconnected.txt";
    FILE *fp = fopen(filename, "w");
    
    for (int v = 5; v <= 50; v += 5) {
        Graph g;
        generateGraph(&g, v, graphType);
        int operations = checkConnectivityAndCycles(&g);
        fprintf(fp, "%d\t%d\n", v, operations);
    }
    fclose(fp);
}

void tester() {
    printf("=== DFS Graph Algorithm Tester ===\n");
    
    // Test Case 1: Simple connected graph with cycle
    Graph g1;
    initGraph(&g1, 4);
    addEdge(&g1, 0, 1);
    addEdge(&g1, 1, 2);
    addEdge(&g1, 2, 3);
    addEdge(&g1, 3, 0); // Creates cycle
    
    printf("Test 1 - Connected graph with cycle (square):\n");
    printf("         Edges: 0-1, 1-2, 2-3, 3-0\n");
    checkConnectivityAndCycles(&g1);
    
    // Test Case 2: Connected graph without cycle (tree)
    Graph g2;
    initGraph(&g2, 4);
    addEdge(&g2, 0, 1);
    addEdge(&g2, 1, 2);
    addEdge(&g2, 1, 3);
    
    printf("\nTest 2 - Connected tree (no cycle):\n");
    printf("         Edges: 0-1, 1-2, 1-3\n");
    checkConnectivityAndCycles(&g2);
    
    // Test Case 3: Disconnected graph
    Graph g3;
    initGraph(&g3, 5);
    addEdge(&g3, 0, 1);
    addEdge(&g3, 2, 3);
    // Vertex 4 is isolated
    
    printf("\nTest 3 - Disconnected graph:\n");
    printf("         Edges: 0-1, 2-3 (vertex 4 isolated)\n");
    checkConnectivityAndCycles(&g3);
    
    // Test Case 4: Single vertex
    Graph g4;
    initGraph(&g4, 1);
    
    printf("\nTest 4 - Single vertex:\n");
    checkConnectivityAndCycles(&g4);
    
    // Test Case 5: Complete graph K4
    Graph g5;
    initGraph(&g5, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            addEdge(&g5, i, j);
        }
    }
    
    printf("\nTest 5 - Complete graph K4:\n");
    printf("         All vertices connected to all others\n");
    checkConnectivityAndCycles(&g5);
    
    printf("\n=== Performance Analysis ===\n");
    printf("Time Complexity: O(V + E) where V = vertices, E = edges\n");
    printf("Space Complexity: O(V) for visited array and recursion stack\n\n");
}

int main() {
    tester();
    printf("=== DFS Graph Analysis ===\n\n");
    
    // Demo with small graph
    Graph demo;
    printf("Demo with 6 vertices:\n");
    generateGraph(&demo, 6, 3); // Disconnected graph
    checkConnectivityAndCycles(&demo);
    
    printf("Generating analysis data...\n");
    plotter(1); // Connected with cycle
    plotter(2); // Connected without cycle
    plotter(3); // Disconnected
    
    printf("DFS analysis complete.\n");
    return 0;
}
