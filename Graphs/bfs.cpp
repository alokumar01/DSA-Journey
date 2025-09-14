#include <iostream>
using namespace std;
#include <vector>
#include<list>
#include <queue>


class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V=7) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++) {
            cout << u << " : ";
            list<int> neighbours = l[u];
            for (int v: neighbours){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfs() { // O(V + E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbours = l[u];
            for(int v : neighbours) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph graph;
    
    // undirected unweighted
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    // graph.print();
    graph.bfs();

    return 0;
}

