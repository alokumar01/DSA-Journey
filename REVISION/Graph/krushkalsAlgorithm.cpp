#include <iostream>
using namespace std;
#include <algorithm>
#include<vector>

class Edge {
public:
    int u;
    int v;
    int wt;    
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;        
    } 
};

class krushkalsAlgorithm {
public:
    vector<Edge> edges;
    vector<int> parent;
    vector<int> rank;
    int V;
    krushkalsAlgorithm(int V) {
        this->V = V;
        for(int i = 0; i < V; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdges(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    // Disjoint Set Data Structure

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]); // path compression, TC --> O(1) almost;
    }

    void unionByRank(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV) {
            return; // cycle condition
        }

        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    void krushkals() {
        //sorting on the edges on the basis of weight;
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {return a.wt < b.wt;});
        int minCost = 0;
        int count = 0;

        for(int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if (parU != parV) {
                unionByRank(parU, parV);
                minCost += e.wt;
            }
        }

        cout << "min cost = " << minCost << endl;
    }
};

int main() {
    krushkalsAlgorithm graph(4);
    graph.addEdges(0, 1, 10);
    graph.addEdges(0, 2, 15);
    graph.addEdges(0, 3, 30);

    graph.addEdges(1, 3, 40);

    graph.addEdges(2, 3, 50);

    graph.krushkals();

    return 0;
}