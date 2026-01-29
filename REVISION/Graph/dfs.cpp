#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

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

    void print(){
        for(int u = 0; u < V; u++) {
            cout << u << ": ";
            for(int neighbour : l[u]) {
                cout << neighbour << " ";
            }
        }
        cout << endl;
    }

    void dfs(int u, vector<bool>& vis) { // O(V + E);
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for(int v : neighbors) {
            if (!vis[v]) {
                dfs(v, vis);
            }
        }
    }

};

int main() {
    Graph graph(7);
    graph.addEdges(0, 1);
    graph.addEdges(0, 2);
    graph.addEdges(1, 3);
    graph.addEdges(2, 4);
    graph.addEdges(3, 4);
    graph.addEdges(3, 5);
    graph.addEdges(4, 5);
    graph.addEdges(5, 6);

    vector<bool> vis(7, false);
    graph.dfs(0, vis);
    // graph.print();
    return 0;
}