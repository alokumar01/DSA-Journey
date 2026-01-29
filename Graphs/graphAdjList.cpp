#include <iostream>
using namespace std;
#include <vector>
#include<list>

// class Graph {
//     int V; 
//     list<pair<int, int>>* l;
// public:
//     Graph(int V=5) {
//         this->V = V;
//         l = new list<pair<int, int>> [V];
//     }

//     void addEdge(int u, int v, int weight) {
//         l[u].push_back({ v, weight });
//         l[v].push_back({ u, weight });
//     }

//     void print() {
//         for(int u=0; u<V; u++) {
//             cout << u << " : ";
//             // list<int> neighbours = l[u];
//             for (auto [v, w] : l[u] ){
//                 cout << "(" << v << "," << w << ")";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graph graph;
//     // undirected weighted
//     graph.addEdge(0, 1, 5);
//     graph.addEdge(1, 2, 1);
//     graph.addEdge(1, 3, 3);
//     graph.addEdge(2, 3, 1);
//     graph.addEdge(2, 4, 2);

//     graph.print();

//     return 0;
// }

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V=5) {
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
};

int main() {
    Graph graph;
    
    // undirected unweighted
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.print();

    return 0;
}

