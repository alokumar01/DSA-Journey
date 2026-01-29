#include<iostream>
using namespace std;
#include<list>

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V = 6) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdges(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    };

    void print() {
        for(int u = 0; u<V; u++) {
            cout << u << ": ";
            for(int neighbour : l[u]) {
                cout << neighbour << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph;
    graph.addEdges(0, 1);
    graph.addEdges(1, 5);
    graph.addEdges(1, 3);
    graph.addEdges(3, 5);
    graph.print();
}
