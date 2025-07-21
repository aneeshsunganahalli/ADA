#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100

int count;
bool visited[MAX_VERTICES];
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
    
    printf("DFS Sort: ");
    for (int i = 0; i < g->vertices; i++) {
        if (topologicalOrder[i] != -1) {
            printf("%d ", topologicalOrder[i]);
        }
    }
    printf("\nOps: %d\n", count);
    
    return count;
}

void generateDAG(DirectedGraph *g, int vertices) {
    initGraph(g, vertices);
    srand(time(NULL));
    
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (rand() % 100 < 30) {
                addEdge(g, i, j);
            }
        }
    }
}

void tester() {
    printf("=== DFS Topological Sort Tester ===\n");
    
    DirectedGraph g1;
    initGraph(&g1, 4);
    addEdge(&g1, 0, 1);
    addEdge(&g1, 1, 2);
    addEdge(&g1, 2, 3);
    
    printf("Test 1 - Linear chain:\n");
    topologicalSortDFS(&g1);
    
    DirectedGraph g2;
    initGraph(&g2, 4);
    addEdge(&g2, 0, 1);
    addEdge(&g2, 0, 2);
    addEdge(&g2, 1, 3);
    addEdge(&g2, 2, 3);
    
    printf("\nTest 2 - Diamond pattern:\n");
    topologicalSortDFS(&g2);
    
    DirectedGraph g3;
    initGraph(&g3, 1);
    
    printf("\nTest 3 - Single vertex:\n");
    topologicalSortDFS(&g3);
    
    printf("\nAll tests completed.\n\n");
}

void plotter() {
    FILE *fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\DFS_Analysis.txt", "w");
    
    for (int v = 5; v <= 50; v += 5) {
        DirectedGraph g;
        generateDAG(&g, v);
        fprintf(fp, "%d\t%d\n", v, topologicalSortDFS(&g));
    }
    fclose(fp);
}

int main() {
    tester();
    printf("Generating analysis data...\n");
    plotter();
    printf("DFS analysis complete.\n");
    return 0;
}
