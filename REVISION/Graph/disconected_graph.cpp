#include <iostream>
using namespace std;
#include<list>
#include <vector>
#include <queue>

class Graph {
    int V;
    list<int>*l;
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
        for(int u = 0; u < V; u++) {
            cout << u << ": ";
            for(int neighbor : l[u]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int src, vector<bool>& vis) {
        cout << src << " ";
        vis[src] = true;

        for (int neighbor : l[src]) {
            if (!vis[neighbor]) {
                dfsHelper(neighbor, vis);
            }
        }
    }

    void dfs() {
        vector<bool>vis(V, false);
        for(int i = 0; i < V; i++) { // this part is important for disconnected graph
            if (!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    void bfsHelper(int src, vector<bool>& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(int neighbor : l[u]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void bfs() {
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if (!vis[i]) {
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }
};


int main() {
    Graph graph(10);
    graph.addEdges(1, 6);
    graph.addEdges(6, 4);
    graph.addEdges(4, 3);
    graph.addEdges(4, 9);
    graph.addEdges(3, 7);
    graph.addEdges(3, 8);

    graph.addEdges(0, 2);
    graph.addEdges(2, 5);

    // graph.dfs();
    // graph.print();

    graph.bfs();
    graph.print();
}

