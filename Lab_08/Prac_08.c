#include <stdio.h>
#include <stdlib.h>
// Structure to represent an edge
typedef struct {
    int u, v;      // vertices
    int weight;    // weight of edge
} Edge;
// Structure to represent a graph
typedef struct {
    int V;         // Number of vertices
    int E;         // Number of edges
    Edge* edges;   // Array of edges
} Graph;
// Function to create a graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*) malloc(E * sizeof(Edge));
    return graph;
}
// Structure for Disjoint Set (Union-Find)
typedef struct {
    int* parent;
    int* rank;
} DisjointSet;
// Create disjoint set
DisjointSet* createDisjointSet(int n) {
    DisjointSet* ds = (DisjointSet*) malloc(sizeof(DisjointSet));
    ds->parent = (int*) malloc(n * sizeof(int));
    ds->rank = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;  // Each node is its own parent initially
        ds->rank[i] = 0;
    }
    return ds;
}
// Find with path compression
int find(DisjointSet* ds, int i) {
    if (ds->parent[i] != i)
        ds->parent[i] = find(ds, ds->parent[i]);
    return ds->parent[i];
}
// Union by rank
void unionSets(DisjointSet* ds, int u, int v) {
    int uroot = find(ds, u);
    int vroot = find(ds, v);

    if (uroot != vroot) {
        if (ds->rank[uroot] < ds->rank[vroot])
            ds->parent[uroot] = vroot;
        else if (ds->rank[uroot] > ds->rank[vroot])
            ds->parent[vroot] = uroot;
        else {
            ds->parent[vroot] = uroot;
            ds->rank[uroot]++;
        }
    }
}
// Compare function for qsort (sort edges by weight)
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}
// Kruskal's algorithm
void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];  // Store edges of MST
    int e = 0;       // Index for result[]
    int i = 0;       // Index for sorted edges
    // Step 1: Sort all edges by weight
    qsort(graph->edges, graph->E, sizeof(Edge), compare);
    // Step 2: Create disjoint set
    DisjointSet* ds = createDisjointSet(V);
    // Step 3: Pick smallest edges one by one
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];

        int u_root = find(ds, next_edge.u);
        int v_root = find(ds, next_edge.v);

        // If including this edge doesn't form a cycle
        if (u_root != v_root) {
            result[e++] = next_edge;   // Include it in MST
            unionSets(ds, u_root, v_root);
        }
    }
    // Step 4: Print MST
    printf("Edges in Minimum Spanning Tree:\n");
    int total_weight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d  weight: %d\n", result[i].u, result[i].v, result[i].weight);
        total_weight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", total_weight);
    free(ds->parent);
    free(ds->rank);
    free(ds);
}
int main() {
    int V = 4;  
    int E = 5;  
    Graph* graph = createGraph(V, E);
    graph->edges[0] = (Edge){0, 1, 10};
    graph->edges[1] = (Edge){0, 2, 6};
    graph->edges[2] = (Edge){0, 3, 5};
    graph->edges[3] = (Edge){1, 3, 15};
    graph->edges[4] = (Edge){2, 3, 4};
    kruskalMST(graph);
    free(graph->edges);
    free(graph);
    return 0;
}
