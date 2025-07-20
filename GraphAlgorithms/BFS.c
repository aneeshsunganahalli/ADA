#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_QUEUE 1000

int count;
bool visited[MAX_VERTICES];
int componentId[MAX_VERTICES];
int currentComponent;

typedef struct {
    int vertices;
    int edges;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

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

bool bfs(Graph *g, int start) {
    Queue q;
    initQueue(&q);
    
    visited[start] = true;
    componentId[start] = currentComponent;
    enqueue(&q, start);
    
    int edgeCount = 0;
    int vertexCount = 0;
    
    while (!isEmpty(&q)) {
        int v = dequeue(&q);
        count++;
        vertexCount++;
        
        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[v][i]) {
                edgeCount++;
                if (!visited[i]) {
                    visited[i] = true;
                    componentId[i] = currentComponent;
                    enqueue(&q, i);
                }
            }
        }
    }
    
    // For undirected graph: if edges >= vertices, there's a cycle in this component
    edgeCount /= 2; // Each edge counted twice in undirected graph
    return edgeCount >= vertexCount;
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
            if (bfs(g, i)) hasCycle = true;
            components++;
        }
    }
    
    printf("BFS Analysis:\n");
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
    printf("BFS Operations: %d\n\n", count);
    
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
    char *filename = graphType == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\BFS_ConnectedWithCycle.txt" :
                     graphType == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\BFS_ConnectedNoCycle.txt" :
                                      "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GraphAlgorithms\\BFS_Disconnected.txt";
    FILE *fp = fopen(filename, "w");
    
    for (int v = 5; v <= 50; v += 5) {
        Graph g;
        generateGraph(&g, v, graphType);
        int operations = checkConnectivityAndCycles(&g);
        fprintf(fp, "%d\t%d\n", v, operations);
    }
    fclose(fp);
}

int main() {
    printf("=== BFS Graph Analysis ===\n\n");
    
    // Demo with small graph
    Graph demo;
    printf("Demo with 6 vertices:\n");
    generateGraph(&demo, 6, 3); // Disconnected graph
    checkConnectivityAndCycles(&demo);
    
    printf("Generating analysis data...\n");
    plotter(1); // Connected with cycle
    plotter(2); // Connected without cycle
    plotter(3); // Disconnected
    
    printf("BFS analysis complete.\n");
    return 0;
}
