#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

// SOLVING BIPARTITE GRAPH (GRAPH COLORING)

class Graph {
    int V;
    list<int>* l; 
    vector<int> color;   
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        this->color = vector<int>(V, -1);
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }


    bool bfsHelper(int src, vector<bool> &vis) {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        color[src] = 0;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : l[u]) {
                if (!vis[v]) { // for unvisited node by level order
                    vis[v] = true;
                    color[v] = !color[u];
                    q.push(v);
                } else { // this is for visited, color same
                    if (color[v] == color[u]){ 
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool bfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]){
                if(!bfsHelper(i, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};


int main() {
    //Undirected bi-partite
    int V = 4;
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    cout << (graph.bfs() ? "Bipartite" : "Not Bipartite") << endl;

    return 0;
}
