#include <iostream>
using namespace std;
#include <vector>
#include<queue>
#include<list>

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdges(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
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

    bool undirCycleHelper(int src, int par, vector<bool> &vis) {
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(undirCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if (v != par) { // cycle condition
                    return true;
                }
            }
        }
        
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }
};

int main() {
    int V = 5;
    Graph graph(V);

    //undirected graph
    graph.addEdges(0, 1);
    graph.addEdges(0, 2);
    graph.addEdges(0, 3);
    graph.addEdges(1, 2);
    graph.addEdges(3, 4);
    
    cout << graph.isCycleUndir() << endl;

    return 0;
}