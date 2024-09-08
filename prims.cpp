#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> Edge; // Pair representing an edge (weight, vertex)

void primMST(int V, const vector<vector<Edge>>& graph) {
    vector<int> minEdge(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    int startVertex = 0; // Start from an arbitrary vertex, in this case vertex 0
    minEdge[startVertex] = 0;
    pq.push({0, startVertex});
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += minEdge[u];

        for (const auto& edge : graph[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (!inMST[v] && weight < minEdge[v]) {
                minEdge[v] = weight;
                pq.push({minEdge[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int v = 1; v < V; ++v) {
        if (parent[v] != -1) {
            cout << parent[v] + 1 << " -- " << v + 1 << " == " << minEdge[v] << endl; // +1 to adjust for 1-based indexing
        }
    }
    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
}

void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    graph[src - 1].push_back({weight, dest - 1}); // -1 to adjust for 0-based indexing
    graph[dest - 1].push_back({weight, src - 1}); // -1 to adjust for 0-based indexing
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter the edges (src dest weight) one per line:\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    primMST(V, graph);

    return 0;
}
