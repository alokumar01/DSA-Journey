#include <vector>
#include <list>
#include <iostream>

using namespace std;

// CYCLE DETECTION FOR DIRECTED

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) { // u -> v
        adj[u].push_back(v);
    }

    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << ": ";
            for (int v : adj[u]) {
                cout << v << " ";
            }   
            cout << endl;
        }
    }

    bool hasDirectedCycleFrom(int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (hasDirectedCycleFrom(v, vis, recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true; // back edge found
            }
        }
        recPath[src] = false;
        return false;
    }

    bool hasDirectedCycle() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (hasDirectedCycleFrom(i, vis, recPath)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};  

int main() {
    int V = 5;
    Graph graph(V); // directed graph

    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << "Cycle detected: " << (graph.hasDirectedCycle() ? "YES" : "NO") << endl;

    return 0;
}
