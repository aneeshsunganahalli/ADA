#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100

int count;    fclose(fp);
}

void tester() {
    printf("=== DFS Topological Sort Tester ===\n");
    
    // Test Case 1: Simple linear dependency chain
    DirectedGraph g1;
    initGraph(&g1, 4);
    addEdge(&g1, 0, 1);
    addEdge(&g1, 1, 2);
    addEdge(&g1, 2, 3);
    
    printf("Test 1 - Linear chain (0->1->2->3):\n");
    topologicalSortDFS(&g1);
    
    // Test Case 2: Tree-like dependencies
    DirectedGraph g2;
    initGraph(&g2, 5);
    addEdge(&g2, 0, 1);
    addEdge(&g2, 0, 2);
    addEdge(&g2, 1, 3);
    addEdge(&g2, 2, 3);
    addEdge(&g2, 3, 4);
    
    printf("\nTest 2 - Tree-like (0->{1,2}, {1,2}->3, 3->4):\n");
    topologicalSortDFS(&g2);
    
    // Test Case 3: Diamond pattern
    DirectedGraph g3;
    initGraph(&g3, 4);
    addEdge(&g3, 0, 1);
    addEdge(&g3, 0, 2);
    addEdge(&g3, 1, 3);
    addEdge(&g3, 2, 3);
    
    printf("\nTest 3 - Diamond pattern (0->{1,2}, {1,2}->3):\n");
    topologicalSortDFS(&g3);
    
    // Test Case 4: Disconnected components
    DirectedGraph g4;
    initGraph(&g4, 6);
    addEdge(&g4, 0, 1);
    addEdge(&g4, 2, 3);
    addEdge(&g4, 4, 5);
    
    printf("\nTest 4 - Disconnected (0->1, 2->3, 4->5):\n");
    topologicalSortDFS(&g4);
    
    // Test Case 5: Single vertex
    DirectedGraph g5;
    initGraph(&g5, 1);
    
    printf("\nTest 5 - Single vertex:\n");
    topologicalSortDFS(&g5);
    
    printf("\n=== Performance Analysis ===\n");
    printf("Time Complexity: O(V + E) - DFS traversal\n");
    printf("Space Complexity: O(V) - Recursion stack and visited array\n");
    printf("Works only on Directed Acyclic Graphs (DAGs)\n\n");
}

int main() {
    tester();
    printf("=== DFS Topological Sort Analysis ===\n\n"); visited[MAX_VERTICES];
int topologicalOrder[MAX_VERTICES];
int orderIndex;

typedef struct {
    int vertices;
    int edges;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int indegree[MAX_VERTICES];
} DirectedGraph;

void initGraph(DirectedGraph *g, int v) {
    g->vertices = v;
    g->edges = 0;
    for (int i = 0; i < v; i++) {
        g->indegree[i] = 0;
        for (int j = 0; j < v; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(DirectedGraph *g, int u, int v) {
    if (!g->adj[u][v]) {
        g->adj[u][v] = 1;
        g->indegree[v]++;
        g->edges++;
    }
}

void dfsTopological(DirectedGraph *g, int v) {
    count++;
    visited[v] = true;
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[v][i] && !visited[i]) {
            dfsTopological(g, i);
        }
    }
    
    // Add to topological order (reverse post-order)
    topologicalOrder[orderIndex--] = v;
}

int topologicalSortDFS(DirectedGraph *g) {
    count = 0;
    orderIndex = g->vertices - 1;
    
    for (int i = 0; i < g->vertices; i++) {
        visited[i] = false;
        topologicalOrder[i] = -1;
    }
    
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            dfsTopological(g, i);
        }
    }
    
    printf("DFS Topological Sort: ");
    for (int i = 0; i < g->vertices; i++) {
        if (topologicalOrder[i] != -1) {
            printf("%d ", topologicalOrder[i]);
        }
    }
    printf("\nDFS Operations: %d\n\n", count);
    
    return count;
}

void generateDAG(DirectedGraph *g, int vertices, int graphType) {
    initGraph(g, vertices);
    srand(time(NULL));
    
    if (graphType == 1) {
        // Linear DAG (chain): 0->1->2->...->n-1
        for (int i = 0; i < vertices - 1; i++) {
            addEdge(g, i, i + 1);
        }
    } else if (graphType == 2) {
        // Tree-like DAG with multiple branches
        for (int i = 1; i < vertices; i++) {
            int parent = i / 2;
            addEdge(g, parent, i);
        }
        // Add some additional edges maintaining DAG property
        for (int i = 0; i < vertices / 3; i++) {
            int u = rand() % (vertices / 2);
            int v = (vertices / 2) + (rand() % (vertices / 2));
            if (u < v) addEdge(g, u, v);
        }
    } else {
        // Dense DAG with many dependencies
        for (int i = 0; i < vertices; i++) {
            for (int j = i + 1; j < vertices; j++) {
                if (rand() % 3 == 0) { // 33% chance of edge
                    addEdge(g, i, j);
                }
            }
        }
    }
}

void plotter(int graphType) {
    char *filename = graphType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Linear.txt" :
                     graphType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Tree.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Dense.txt";
    FILE *fp = fopen(filename, "w");
    
    for (int v = 5; v <= 50; v += 5) {
        DirectedGraph g;
        generateDAG(&g, v, graphType);
        int operations = topologicalSortDFS(&g);
        fprintf(fp, "%d\t%d\n", v, operations);
    }
    fclose(fp);
}

int main() {
    printf("=== DFS-based Topological Sort Analysis ===\n\n");
    
    // Demo with small graph
    DirectedGraph demo;
    printf("Demo with 6 vertices (Tree-like DAG):\n");
    generateDAG(&demo, 6, 2);
    
    printf("Graph edges:\n");
    for (int i = 0; i < demo.vertices; i++) {
        for (int j = 0; j < demo.vertices; j++) {
            if (demo.adj[i][j]) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
    printf("\n");
    
    topologicalSortDFS(&demo);
    
    printf("Generating analysis data...\n");
    plotter(1); // Linear DAG
    plotter(2); // Tree-like DAG
    plotter(3); // Dense DAG
    
    printf("DFS Topological Sort analysis complete.\n");
    return 0;
}
