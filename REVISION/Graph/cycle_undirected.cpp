#include <iostream>
using namespace std;
#include <list>
#include<vector>

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
        for (int u = 0; u < V; u++) {
            cout << u << ":  ";
            for (int neighbor : l[u]) {
                cout << neighbor << " ";
            }
        }
        cout << endl;
    }

    bool dfs(int src, vector<bool>& vis, int parent) {
        vis[src] = true;

        for(int neighbor : l[src]) {
            if (!vis[neighbor]) {
                if(dfs(neighbor, vis, src)) { // yaha par if condition important hai, taki dfs answer propagate kar sake
                    return true; // agar if condition nahi hua then dfs bolega, tum search karte raho mujhe ghanta fark padta hai
                }
            } else {
                if (parent != neighbor) {
                    return true; // means cycle mil gya
                }
            }
        }
        return false;
    }
};


int main() {
    Graph graph(7);
    graph.addEdges(0, 1);
    // graph.addEdges(0, 2);
    graph.addEdges(0, 3);
    graph.addEdges(1, 2);
    graph.addEdges(3, 4);


    vector<bool> vis(4, false);
    int res = graph.dfs(0, vis, -1);

    if (res) {
        cout << "CYCLE MIL GYA SARKAR";
    } else {
        cout << "NAHI MILA CYCLE"; 
    }
    return 0;
}