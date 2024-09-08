#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void BFS(unordered_map<string, vector<string>> G, string s) {
    unordered_map<string, string> colour;
    unordered_map<string, int> d;
    unordered_map<string, string> p;

    for (auto& pair : G) {
        string u = pair.first;
        if (u != s) {
            colour[u] = "W";
            d[u] = INT_MAX;
            p[u] = "NIL";
        }
    }

    colour[s] = "G";
    d[s] = 0;
    p[s] = "NIL";

    queue<string> Q;
    Q.push(s);

    while (!Q.empty()) {
        string u = Q.front();
        Q.pop();
        for (auto& v : G[u]) {
            if (colour[v] == "W") {
                colour[v] = "G";
                d[v] = d[u] + 1;
                p[v] = u;
                Q.push(v);
            }
        }
        colour[u] = "B";
    }

    cout << "BFS Spanning Tree:\n";
    for (auto& pair : G) {
        string child = pair.first;
        if (child != s) {
            string parent = p[child];
            cout << parent << "->" << child << endl;
        }
    }

    cout << "\nDistances from start vertex " << s << ":\n";
    for (auto& pair : d) {
        string vertex = pair.first;
        int distance = pair.second;
        cout << "Distance to " << vertex << " is " << distance << endl;
    }
}

int main() {
    int E;  // Number of edges
    cout << "Enter the number of edges: ";
    cin >> E;

    unordered_map<string, vector<string>> G;
    cout << "Enter the edges (src dest) one per line:\n";
    for (int i = 0; i < E; ++i) {
        string src, dest;
        cin >> src >> dest;
        G[src].push_back(dest);
        G[dest].push_back(src);  // If the graph is undirected
    }

    string start_vertex;
    cout << "Enter the start vertex: ";
    cin >> start_vertex;

    BFS(G, start_vertex);

    return 0;
}
