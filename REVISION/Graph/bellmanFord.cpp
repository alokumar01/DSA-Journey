//Shortest part from source to all vertices for weighted graph with negative wt;

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Edge{
public:
    int v;
    int wt;
    
    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanford(vector<vector<Edge>> graph, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V-1; i++) { // O(V.E) not good TC AS Dijkstra 
        for (int u = 0; u < V; u++) { // edges
            for(Edge e : graph[u]) { // all neighbors of that edges
                if (dist[u] + e.wt < dist[e.v]) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for (int d : dist) {
        cout << d << " ";
    }
}


int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);
    graph[0].push_back(Edge(1, 2)); //first vertice, second weight from Edge class;
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));
    
    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -10));

    bellmanford(graph, V, 1);

    return 0;
}