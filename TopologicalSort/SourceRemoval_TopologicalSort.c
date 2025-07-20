#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_QUEUE 1000

int count;

typedef struct {
    int vertices;
    int edges;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int indegree[MAX_VERTICES];
} DirectedGraph;

typedef struct {
    int items[MAX_QUEUE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_QUEUE - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

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

int topologicalSortSourceRemoval(DirectedGraph *g) {
    count = 0;
    Queue q;
    initQueue(&q);
    int result[MAX_VERTICES];
    int resultIndex = 0;
    
    // Create a copy of indegrees to avoid modifying original
    int tempIndegree[MAX_VERTICES];
    for (int i = 0; i < g->vertices; i++) {
        tempIndegree[i] = g->indegree[i];
    }
    
    // Find all vertices with indegree 0 (sources)
    for (int i = 0; i < g->vertices; i++) {
        count++; // Operation to check indegree
        if (tempIndegree[i] == 0) {
            enqueue(&q, i);
        }
    }
    
    printf("Source Removal Topological Sort: ");
    
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        count++; // Operation to process vertex
        result[resultIndex++] = u;
        printf("%d ", u);
        
        // For each adjacent vertex, reduce indegree
        for (int v = 0; v < g->vertices; v++) {
            if (g->adj[u][v]) {
                count++; // Operation to process edge
                tempIndegree[v]--;
                if (tempIndegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }
    
    printf("\nSource Removal Operations: %d\n", count);
    
    // Check for cycles
    if (resultIndex != g->vertices) {
        printf("Graph contains a cycle!\n");
    }
    printf("\n");
    
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
    char *filename = graphType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\SourceRemoval_Linear.txt" :
                     graphType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\SourceRemoval_Tree.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\TopologicalSort\\SourceRemoval_Dense.txt";
    FILE *fp = fopen(filename, "w");
    
    for (int v = 5; v <= 50; v += 5) {
        DirectedGraph g;
        generateDAG(&g, v, graphType);
        int operations = topologicalSortSourceRemoval(&g);
        fprintf(fp, "%d\t%d\n", v, operations);
    }
    fclose(fp);
}

int main() {
    printf("=== Source Removal Topological Sort Analysis ===\n\n");
    
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
    
    printf("Indegrees: ");
    for (int i = 0; i < demo.vertices; i++) {
        printf("v%d(%d) ", i, demo.indegree[i]);
    }
    printf("\n\n");
    
    topologicalSortSourceRemoval(&demo);
    
    printf("Generating analysis data...\n");
    plotter(1); // Linear DAG
    plotter(2); // Tree-like DAG
    plotter(3); // Dense DAG
    
    printf("Source Removal Topological Sort analysis complete.\n");
    return 0;
}
