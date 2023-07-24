Detect Cycle Undirected graph

#include <iostream>
#include <vector>
using namespace std;

bool isCyclicUtil(int v, vector<vector<int>>& adjList, vector<bool>& visited, int parent) {
    visited[v] = true;

    for (int u : adjList[v]) {
        if (!visited[u]) {
            if (isCyclicUtil(u, adjList, visited, v))
                return true;
        } else if (u != parent) {
            // If the vertex is already visited and not the parent of the current vertex, it forms a cycle
            return true;
        }
    }

    return false;
}

bool isCyclic(vector<vector<int>>& adjList, int n) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, adjList, visited, -1))
                return true;
        }
    }

    return false;
}

int main() {
    int n = 6; // Number of vertices in the graph

    vector<vector<int>> adjList(n); // Graph representation using adjacency list

    // Add undirected edges to the graph
    adjList[0].push_back(1);
    adjList[1].push_back(0);

    adjList[1].push_back(2);
    adjList[2].push_back(1);

    adjList[2].push_back(3);
    adjList[3].push_back(2);

    adjList[3].push_back(4);
    adjList[4].push_back(3);

    // Uncomment the following line to add a cycle (uncomment only one line)
    // adjList[4].push_back(0); // Cycle between 0 and 4
    // adjList[5].push_back(2); // Cycle between 2 and 5

    if (isCyclic(adjList, n)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}