#include <stdio.h>
#include <stdlib.h>

#define MAX 50 // Maximum number of cities/vertices

int a[MAX][MAX], n, visited[MAX];  // Adjacency matrix, number of vertices, visited array
int q[MAX], front = -1, rear = -1; // Queue for BFS
int s[MAX], top = -1;              // Stack for DFS

// Function to implement BFS (Breadth-First Search)
void bfs(int v)
{
    int i, cur;
    visited[v] = 1;
    q[++rear] = v; // Enqueue the starting vertex

    while (front != rear)
    {
        cur = q[++front]; // Dequeue a vertex
        for (i = 1; i <= n; i++)
        {
            if ((a[cur][i] == 1) && (visited[i] == 0))
            {                     // If there's an edge and the node is unvisited
                q[++rear] = i;    // Enqueue the unvisited vertex
                visited[i] = 1;   // Mark the vertex as visited
                printf("%d ", i); // Print the visited vertex
            }
        }
    }
}

// Function to implement DFS (Depth-First Search)
void dfs(int v)
{
    int i;
    visited[v] = 1;
    s[++top] = v; // Push the starting vertex onto the stack

    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {                     // If there's an edge and the node is unvisited
            printf("%d ", i); // Print the visited vertex
            dfs(i);           // Recursively visit the adjacent vertex
        }
    }
}

int main()
{
    int ch, start, i, j;

    // Input the number of vertices
    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix (0 or 1):\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]); // 1 indicates an edge between nodes i and j
        }
    }

    // Initialize the visited array
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0; // Mark all vertices as unvisited
    }

    // Input the starting vertex for BFS/DFS
    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    // Menu for choosing between BFS, DFS, and Exit
    while (1)
    {
        printf("\n==> 1. BFS: Print all nodes reachable from a given starting node");
        printf("\n==> 2. DFS: Print all nodes reachable from a given starting node");
        printf("\n==> 3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nNodes reachable from starting vertex %d using BFS: ", start);
            bfs(start);
            // Check for unreachable nodes
            for (i = 1; i <= n; i++)
            {
                if (visited[i] == 0 && i != start)
                { // Exclude the starting vertex
                    printf("\nVertex %d is not reachable.", i);
                }
            }
            break;

        case 2:
            printf("\nNodes reachable from starting vertex %d using DFS: ", start);
            dfs(start);
            break;

        case 3:
            exit(0); // Exit the program

        default:
            printf("\nInvalid choice. Please try again.");
        }

        // Reset visited array for next operation (BFS/DFS)
        for (i = 1; i <= n; i++)
        {
            visited[i] = 0;
        }
    }

    return 0;
}
