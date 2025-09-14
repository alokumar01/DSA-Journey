#include <iostream>
using namespace std;
#include <list>
#include<queue>
#include<vector>

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

    //print fxn
    bool bfsHelper(int src, vector<bool> &vis) {
        queue<int> q;
        q.push(0);
        vis[0] = true;
        color[0] = 0;
        
        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            list<int> neighbors = l[u];

            for(int v : neighbors) {
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
    int V=4;
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    cout << graph.bfs() << endl;

    return 0;
}