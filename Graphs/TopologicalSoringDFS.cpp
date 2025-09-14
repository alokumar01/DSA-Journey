#include <iostream>
using namespace std;
#include<list>
#include<vector>
#include <stack>


class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V=6) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdges(int u, int v) {
        l[u].push_back(v);
        // l[v].push_back(u);
    }

    //print fxn

    void topoSortingHelper(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;
        // cout << src << " ";

        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if (!vis[v]) {
                topoSortingHelper(v, vis, s);
            }
        }
        s.push(src);
    }

    void dfs() {
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++) {
            if (!vis[i]) {
                topoSortingHelper(i, vis, s);
            }
        }

        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }

};

int main() {
    //DAG
    Graph graph;
    
    graph.addEdges(5, 0);
    graph.addEdges(5, 2);
    graph.addEdges(2, 3);
    graph.addEdges(3, 1);
    graph.addEdges(4, 0);
    graph.addEdges(4, 1);

    graph.dfs();

    return 0;
}