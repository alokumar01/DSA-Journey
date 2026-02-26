#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->v = wt;
    }
};
    
    void dijkastra(int src, vector<vector<Edge>>& graph, int V) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
        
        vector<int> dist(V, INT_MAX);
        //create a distance vector and mark all with INT_MAX;
        pq.push({ 0, src });
        dist[src] = 0;

        while (pq.size() > 0) {
            int u = pq.top().second; pq.pop();
            for(Edge e : graph[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({ dist[e.v], e.v });
                }
            }
        }
        
        for(int d : dist) {
            cout << d << " "; 
        }

        cout << endl;
    }

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2)); // first vertex, second weight
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    dijkastra(0, graph, V);

    return 0;
}