#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define an edge structure to store the source, destination, and weight of each edge
struct Edge {
    int src, dest, weight;
};

// Function to create a graph with V vertices
vector<Edge> createGraph(int V) {
    vector<Edge> graph;
    return graph;
}

// Find function for the union-find data structure
int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// Union function for the union-find data structure
void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(int V, vector<Edge>& graph) {
    vector<Edge> result; // This will store the resulting MST
    int totalWeight = 0; // Variable to store the total weight of the MST

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(graph.begin(), graph.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Initialize union-find data structures
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int v = 0; v < V; ++v) {
        parent[v] = v;
    }

    // Step 2: Pick the smallest edge and add it to the MST if it doesn't form a cycle
    for (auto& edge : graph) {
        int setU = find(parent, edge.src); // 0-based indexing
        int setV = find(parent, edge.dest); // 0-based indexing

        if (setU != setV) {
            result.push_back(edge);
            totalWeight += edge.weight;
            unionSets(parent, rank, setU, setV);
        }
    }

    // Print the edges in the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& edge : result) {
        cout << edge.src + 1 << " -- " << edge.dest + 1 << " == " << edge.weight << endl; // +1 to adjust for 1-based indexing
    }
    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
}

// Function to add an edge to the graph
void addEdge(vector<Edge>& graph, int src, int dest, int weight) {
    graph.push_back({src - 1, dest - 1, weight}); // -1 to adjust for 0-based indexing
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> graph = createGraph(V);

    cout << "Enter the edges (src dest weight) one per line:\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    kruskalMST(V, graph);

    return 0;
}
