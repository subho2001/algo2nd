#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
#include <string>   // For handling "INF" input
#include <sstream>  // For converting input strings
using namespace std;

#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's algorithm for a graph represented using an adjacency matrix
void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INF);  // The output array. dist[i] holds the shortest distance from src to i
    vector<bool> sptSet(V, false);  // sptSet[i] is true if vertex i is included in the shortest path tree

    dist[src] = 0;  // Distance of source vertex from itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if it's not yet in sptSet, there's an edge from u to v,
            // and the total weight of the path from src to v through u is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    // Input graph as adjacency matrix
    cout << "Enter the adjacency matrix (use INF for no direct edge between vertices):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            string input;
            cin >> input;

            if (input == "INF") {
                graph[i][j] = INF;  // Assign INT_MAX for no edge
            } else {
                stringstream ss(input);
                ss >> graph[i][j];  // Convert string to integer
            }
        }
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, src, V);  // Run Dijkstra's algorithm from the source vertex

    return 0;
}
