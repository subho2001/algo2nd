#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>

using namespace std;

unordered_map<string, string> color;   // Stores the color of each vertex (W = White, G = Gray, B = Black)
unordered_map<string, string> parent;  // Stores the parent of each vertex
unordered_map<string, int> pre;        // Stores the discovery time (pre-visit)
unordered_map<string, int> post;       // Stores the finish time (post-visit)
stack<string> topoStack;               // Stack to store topologically sorted vertices
int time;                              // Global time tracker

// DFS Visit function for the recursive depth-first search
void DFS_VISIT(unordered_map<string, vector<string>>& G, string u) {
    color[u] = "G";        // Mark the vertex as visited (Gray)
    time += 1;
    pre[u] = time;         // Record the pre-visit time

    for (auto& v : G[u]) { // Visit all adjacent vertices
        if (color[v] == "W") {
            parent[v] = u;  // Set the parent of vertex v
            DFS_VISIT(G, v); // Recursively visit the adjacent vertex
        }
    }

    color[u] = "B";        // Mark the vertex as fully processed (Black)
    time += 1;
    post[u] = time;        // Record the post-visit time
    topoStack.push(u);     // Push the vertex onto the stack after all its neighbors are visited
}

// Main DFS function that initializes and performs DFS on the graph
void DFS(unordered_map<string, vector<string>>& G, const vector<string>& vertices) {
    // Initialization
    for (const auto& u : vertices) {
        color[u] = "W";    // All vertices initially unvisited (White)
        parent[u] = "NIL"; // No parent initially
    }

    time = 0;

    // Perform DFS for each unvisited vertex
    for (const auto& u : vertices) {
        if (color[u] == "W") {
            DFS_VISIT(G, u);
        }
    }
}

// Function to print the topological sort
void printTopologicalSort() {
    cout << "\nTopological Sort:\n";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;
}

int main() {
    unordered_map<string, vector<string>> G;
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the vertices:\n";
    vector<string> vertices(numVertices);
    for (int i = 0; i < numVertices; i++) {
        cin >> vertices[i];
    }

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (format: src dest) one per line:\n";
    for (int i = 0; i < numEdges; i++) {
        string u, v;
        cin >> u >> v;
        G[u].push_back(v);  // Add directed edge from u to v
    }

    // Ensure all vertices are part of the graph (even if they have no outgoing edges)
    for (const auto& vertex : vertices) {
        if (G.find(vertex) == G.end()) {
            G[vertex] = {}; // Add vertex with no outgoing edges
        }
    }

    // Perform DFS on the graph
    DFS(G, vertices);

    // Output the pre-visit and post-visit times
    cout << "Vertex\tPre\tPost\n";
    for (const auto& vertex : vertices) {
        cout << vertex << "\t" << pre[vertex] << "\t" << post[vertex] << endl;
    }

    // Output the topological sort
    printTopologicalSort();

    return 0;
}
