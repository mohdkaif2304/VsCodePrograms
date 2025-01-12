#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a class to represent a graph
class Graph {

    
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph
    }

    // Function to perform BFS traversal starting from a given vertex
    void BFS(int start) {
        // Create a boolean array to keep track of visited vertices
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            // Dequeue a vertex from the queue and print it
            int current = q.front();
            cout << current << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // Create a graph
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    
    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
