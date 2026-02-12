#include<iostream>
using namespace std;
#include <list>
#include <vector>
#include <queue>

//BIPARTITE GRAPH
// 1st approach is Graph Coloring

class Graph {
    int V;
    list<int>* l;    
    vector<int> color;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
        this->color = vector<int>(V, -1);
    }

    void addEdges(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool bfsHelper(int src, vector<bool>& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        color[src] = 0;

        while (!q.empty()) {
            int u  = q.front(); q.pop();

            for(int neighbor : l[u]) {
                if (!vis[neighbor]) { // first condition if not visited then mark neighbor true and assign differnt color to neightbor then push neighbor into queue
                    vis[neighbor] = true;
                    color[neighbor] = !color[u];
                    q.push(neighbor);
                } else {
                    if (color[u] == color[neighbor]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool bfs() {
        vector<bool> vis(V, false);
        if (V == 0) return true;

        if (!bfsHelper(0, vis)) {
            return false;
        }

        // Disconnected graph allowed nahi hai.
        for (int i = 0; i < V; i++) {
            if (!vis[i]) return false;
        }

        return true;
    }
};


int main() {
    Graph graph(5);
    graph.addEdges(0, 1);
    graph.addEdges(0, 2);
    graph.addEdges(1, 3);
    graph.addEdges(2, 4);
    graph.addEdges(3, 4);
    
    cout << (graph.bfs() ? "GRAPH BIPARTITE HAI" : "GRAPH BIPARTITE NAHI HAI");
}
