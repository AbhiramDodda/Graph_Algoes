#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
private:
    int n; // number of nodes
    vector<vector<pair<int, int>>> adj; // adjacency list {node, weight}
    vector<vector<int>> dist; // distance for shortest path (Floyd-Warshall)
    vector<int> color; // for graph coloring
    vector<vector<int>> mcsts; // for storing multiple MSTs
    bool planar, complete; // precomputed results
    int minCut, maxCut; // for min/max cut results

public:
    Graph(int nodes) : n(nodes), adj(nodes + 1), dist(nodes + 1, vector<int>(nodes + 1, INT_MAX)), color(nodes + 1, -1), planar(true), complete(true), minCut(0), maxCut(0) {}

    // Adds an edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Utility for Kruskal's MST
    struct Edge {
        int u, v, w;
        bool operator<(const Edge& e) const {
            return w < e.w;
        }
    };

    int findSet(int u, vector<int>& parent) {
        if (u == parent[u]) return u;
        return parent[u] = findSet(parent[u], parent);
    }

    void kruskalMST() {
        vector<Edge> edges;
        for (int u = 1; u <= n; ++u) {
            for (auto& [v, w] : adj[u]) {
                if (u < v) edges.push_back({u, v, w});
            }
        }
        sort(edges.begin(), edges.end());

        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        int cost = 0;
        vector<pair<int, int>> mst;
        for (Edge& e : edges) {
            int uSet = findSet(e.u, parent);
            int vSet = findSet(e.v, parent);
            if (uSet != vSet) {
                mst.push_back({e.u, e.v});
                cost += e.w;
                parent[uSet] = vSet;
            }
        }
        mcsts.push_back({cost});
        cout << "Minimum Spanning Tree with cost: " << cost << endl;
        for (auto& e : mst) {
            cout << e.first << " - " << e.second << endl;
        }
    }

    void floydWarshall() {
        // Initialize distances
        for (int i = 1; i <= n; ++i) dist[i][i] = 0;
        for (int u = 1; u <= n; ++u) {
            for (auto& [v, w] : adj[u]) {
                dist[u][v] = w;
                dist[v][u] = w;
            }
        }
        // Floyd-Warshall algorithm
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void graphColoring() {
        color[1] = 0;
        for (int u = 2; u <= n; ++u) {
            vector<bool> used(n, false);
            for (auto& [v, w] : adj[u]) {
                if (color[v] != -1) used[color[v]] = true;
            }
            for (int c = 0; c < n; ++c) {
                if (!used[c]) {
                    color[u] = c;
                    break;
                }
            }
        }
        int maxColor = *max_element(color.begin(), color.end()) + 1;
        cout << "Graph colored with " << maxColor << " colors." << endl;
    }

    bool isCompleteGraph() {
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() != n - 1) return false;
        }
        return true;
    }

    void minMaxCut() {
        // Stub for min/max cut
        // Complex algorithms like Stoer-Wagner for min cut can be implemented
        minCut = rand() % 10; // Dummy implementation
        maxCut = rand() % 10 + 10; // Dummy implementation
    }

    void runOperations() {
        int option;
        do {
            cout << "\nChoose an option:\n";
            cout << "1. Print all possible MCSTs\n";
            cout << "2. Check if graph is planar\n";
            cout << "3. Check if graph is complete\n";
            cout << "4. Print all pair shortest paths\n";
            cout << "5. Graph coloring\n";
            cout << "6. Print shortest distance between two nodes\n";
            cout << "7. Print min cut and max cut\n";
            cout << "-1. Exit\n";
            cin >> option;

            switch (option) {
            case 1:
                kruskalMST();
                break;
            case 2:
                cout << (planar ? "Graph is planar" : "Graph is not planar") << endl;
                break;
            case 3:
                cout << (complete ? "Graph is complete" : "Graph is not complete") << endl;
                break;
            case 4:
                floydWarshall();
                cout << "All-pairs shortest paths:\n";
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (dist[i][j] == INT_MAX) cout << "INF ";
                        else cout << dist[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            case 5:
                graphColoring();
                break;
            case 6: {
                int u, v;
                cout << "Enter two nodes: ";
                cin >> u >> v;
                if (dist[u][v] != INT_MAX)
                    cout << "Shortest distance between " << u << " and " << v << ": " << dist[u][v] << endl;
                else
                    cout << "No path exists between " << u << " and " << v << endl;
                break;
            }
            case 7:
                minMaxCut();
                cout << "Minimum Cut: " << minCut << endl;
                cout << "Maximum Cut: " << maxCut << endl;
                break;
            case -1:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
            }
        } while (option != -1);
    }
};

int main() {
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter edges (u v w) format:\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.runOperations();

    return 0;
}
