#include <iostream>
using namespace std;
#include <vector>
#include<queue>
#include <list>

// Algorithm Structure

// We need:
// Min heap (priority queue)
// Visited array
// Adjacency list

// Pseudocode
// 1. Start from node 0
// 2. Push (0, start) in min heap
// 3. While heap not empty:
//        pop smallest weight edge
//        if node already visited → skip
//        mark visited
//        add weight to answer
//        push all adjacent edges


class Graph {
public:
    int V;
    list<pair<int, int>>* l; // neighbors and weight

    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>> [V];
    }
    
    void addEdges(int u, int v, int wt) {
        l[u].push_back({ v, wt });
        l[v].push_back({ u, wt });
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(V, false);
        pq.push({ 0, src }); // weight, node

        int cost = 0;

        
        while (!pq.empty()) {
            auto [wt, u] = pq.top(); 
            pq.pop();
            
            if (!vis[u]) {
                vis[u] = true;
                cost += wt;
                for (pair<int, int> neighbors : l[u]) {
                    int v = neighbors.first;
                    int edgewt = neighbors.second;
                    pq.push({ edgewt, v });
                }
            }
        }

        cout << "Minimum cost to cover all the points: " << cost << endl;
    }
};

int main() {
    Graph graph(4);
    graph.addEdges(0, 1, 2);
    graph.addEdges(0, 2, 3);
    graph.addEdges(0, 3, 6);

    graph.addEdges(1, 2, 8);

    graph.addEdges(2, 3, 5);


    graph.primsAlgo(0);

    return 0;
}