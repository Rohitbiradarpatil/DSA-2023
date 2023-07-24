#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
    // No. of vertices
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

// Destructor
void Graph_destroy(Graph* g)
{
    free(g);
}

// Function to add an edge to the graph
void Graph_addEdge(Graph* g, int v, int w)
{
    // Add w to v’s list
    g->adj[v][w] = true;
}

// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;

    while (front != rear) {
        // Dequeue a vertex from the queue and print it
        s = queue[front++];
        printf("%d ", s);

        // Get all adjacent vertices of the dequeued vertex s.
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (int adjacent = 0; adjacent < g->V; adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

// DFS traversal function
void Graph_DFSUtil(Graph* g, int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    printf("%d ", v);

    // Recur for all the adjacent vertices of the current vertex
    for (int adjacent = 0; adjacent < g->V; adjacent++) {
        if (g->adj[v][adjacent] && !visited[adjacent]) {
            Graph_DFSUtil(g, adjacent, visited);
        }
    }
}

// DFS traversal function
void Graph_DFS(Graph* g, int v)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function
    Graph_DFSUtil(g, v, visited);
}

// Driver code
int main()
{
    int k, m, n, q, r;
    printf("NO OF VERTICE\n");
    scanf("%d", &m);
    Graph* g = Graph_create(m);

    while (1) {
        printf("\t 1: Add edge\t 2: BFS traversal \t 3: DFS traversal\t 4: Quit\n");
        scanf("%d", &k);

        switch (k) {
            case 1:
                printf("SOURCE AND DESTINATION\n");
                scanf("%d%d", &n, &q);
                Graph_addEdge(g, n, q);
                break;
            case 2:
                printf("GET Breadth First Traversal starting from vertex: ");
                scanf("%d", &r);
                Graph_BFS(g, r);
                printf("\n");
                break;
            case 3:
                printf("GET Depth First Traversal starting from vertex: ");
                scanf("%d", &r);
                Graph_DFS(g, r);
                printf("\n");
                break;
            case 4:
                Graph_destroy(g);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
