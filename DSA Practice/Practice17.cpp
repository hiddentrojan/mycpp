#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal of the graph
void DFS(vector<vector<int>>& adj, int currentVertex, vector<bool>& visited) {
    cout << currentVertex << " "; // Process the current vertex
    visited[currentVertex] = true;

    // Traverse all adjacent vertices of the current vertex
    for (int i = 0; i < adj.size(); i++) {
        if (adj[currentVertex][i] == 1 && !visited[i]) {
            DFS(adj, i, visited);
        }
    }
}

int main() {
    // Already initialized adjacency matrix
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int n = adj.size();
    vector<bool> visited(n, false); // Mark all vertices as not visited

    cout << "DFS Traversal: ";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(adj, i, visited);
        }
    }

    return 0;
}