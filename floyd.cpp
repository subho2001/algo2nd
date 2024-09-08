#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int INF = 99999;

// Function to print the reconstructed path
void printPath(vector<vector<int>>& pi, int i, int j) {
    if (i == j) {
        cout << i + 1 << " ";  // Print the vertex (1-indexed)
    } else if (pi[i][j] == -1) {
        cout << "No path";
    } else {
        printPath(pi, i, pi[i][j]);
        cout << j + 1 << " ";  // Print the destination vertex
    }
}

// Function to print the solution matrices and paths
void printSolution(vector<vector<int>> dist, vector<vector<int>> pi, int V) {
    cout << "The shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\nThe intermediate vertices for the shortest paths:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (pi[i][j] == -1)
                cout << "NIL ";
            else
                cout << pi[i][j] + 1 << "   ";
        }
        cout << endl;
    }

    // Print the paths between all pairs of vertices
    cout << "\nThe paths between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << "Path from " << i + 1 << " to " << j + 1 << ": ";
                printPath(pi, i, j);
                cout << endl;
            }
        }
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>> dist, int V) {
    vector<vector<int>> pi(V, vector<int>(V, -1));

    // Initialize the predecessor matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] != INF && i != j) {
                pi[i][j] = i;
            }
        }
    }

    // Run the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }

    // Print the results
    printSolution(dist, pi, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (INF for infinity):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            string input;
            cin >> input;
            if (input == "INF") {
                graph[i][j] = INF;
            } else {
                stringstream ss(input);
                int weight;
                ss >> weight;
                graph[i][j] = weight;
            }
        }
    }

    floydWarshall(graph, V);
    return 0;
}
