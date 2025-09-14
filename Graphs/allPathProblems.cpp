#include <iostream>
using namespace std;
#include<vector>
#include<list>
#include<string>    

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
    }

    void dfsHelper(int src, int dest, vector<bool> &vis, string &path) {
        if (src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);

        list<int> neighbours = l[src];
        for(int v : neighbours) {
            if (!vis[v]) {
                dfsHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void dfs(int src, int dest) {
        string path = "";
        vector<bool> vis(V, false);
        dfsHelper(src, dest, vis, path);
    }

};

int main() {
    int V=10;
    Graph graph(V);
    // ALL PATH PROBLEMS
    // Unweighted Directed
    graph.addEdge(5, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(5, 0);
    graph.addEdge(0, 3);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);

    graph.dfs(5, 1);
    
    

    return 0;
}