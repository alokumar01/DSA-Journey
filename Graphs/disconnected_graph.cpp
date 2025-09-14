#include <iostream>
using namespace std;
#include <vector>
#include<list>
#include <queue>


class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V=10) {
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

    void bfsHelper(int st, vector<bool> &vis) {
        queue<int> q;
        q.push(st);
        vis[st] = true;

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

    void bfs() { // O(V + E)
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                bfsHelper(i, vis);
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;
        list<int> neighbours = l[u];

        for(int v : neighbours) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() { // O(V + E)
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if (!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph graph;
    
    // undirected unweighted
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 7);
    graph.addEdge(3, 8);

    graph.addEdge(2, 0);
    graph.addEdge(2, 5);

    // graph.print();
    // graph.bfs();

    cout << "DFS Traversal (Disconnected Graph): " << endl;
    graph.dfs();

    
    cout << "\nBFS Traversal (Disconnected Graph): " << endl;
    graph.bfs();


    
    return 0;
}

