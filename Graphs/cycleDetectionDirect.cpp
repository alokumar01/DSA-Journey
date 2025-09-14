#include <iostream>
using namespace std;
#include <vector>
#include<queue>
#include<list>

// CYCLE DETECTION FOR DIRECTED

class Graph {
    int V;
    list<int>* l;
    bool isUndir;
public:
    Graph(int V, bool isUndir=true) {
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdges(int u, int v) { // u--->v
        l[u].push_back(v); // 
        if(isUndir) {
            l[v].push_back(u);
        }
    }

    void print() {
        for(int u=0; u<V; u++) {
            cout << u <<  " ";
            list<int> neighbours = l[u];
            for (int v : neighbours) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neightbors = l[src];

        for(int v : neightbors) {
            if(!vis[v]) {
                if(dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dirCycleHelper(i, vis, recPath)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};  

int main() {
    int V = 5;
    Graph graph(V, false);
    //directed graph
    graph.addEdges(1, 0);
    graph.addEdges(0, 2);
    graph.addEdges(2, 3);
    graph.addEdges(3, 0);    
    cout << graph.isCycleDir() << endl;

    return 0;
}