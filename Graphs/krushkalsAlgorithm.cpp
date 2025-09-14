#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


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

class Graph {
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V) {
        this->V = V;

        for(int i=0; i<V; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v) {
        int parU = find(u);
        int parV = find(v);

        if(rank[parV] == rank[parV]) {
            par[parV] = parU;
            rank[parU]++;
        } else if (rank[parU] > rank[parV]) {
            par[parV] = parU;
        } else {
            par[parU] = parV;
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    void krushkals() { // TC - O(E log E);
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});
        int minCost = 0;
        int count = 0;

        for(int i=0; i<edges.size() && count < V-1; i++) {
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);
            if(parU != parV) { //no cycle
                unionByRank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }
        
        cout << "min cost = " << minCost << endl;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.krushkals();

    return 0;
}



// class Edge {
// public:
//     int u, v, wt;
//     Edge(int u, int v, int wt) {
//         this->u = u;
//         this->v = v;
//         this->wt = wt;
//     }
// };

// class DisjointSet {
// public:
//     vector<int> parent, rank;

//     DisjointSet(int n) {
//         parent.resize(n);
//         rank.resize(n, 0);
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
//     }

//     int find(int x) {
//         if (parent[x] == x)
//             return x;
//         return parent[x] = find(parent[x]);
//     }

//     void unionByRank(int u, int v) {
//         int pu = find(u);
//         int pv = find(v);

//         if (pu == pv) return;

//         if (rank[pu] < rank[pv]) {
//             parent[pu] = pv;
//         } else if (rank[pu] > rank[pv]) {
//             parent[pv] = pu;
//         } else {
//             parent[pv] = pu;
//             rank[pu]++;
//         }
//     }
// };


// class Solution {
// public:
//     int kruskalsMST(int V, vector<vector<int>> &edges) {
//         vector<Edge> edgeList;
//         for (auto &e : edges) {
//             edgeList.push_back(Edge(e[0], e[1], e[2]));
//         }


//         sort(edgeList.begin(), edgeList.end(), [](Edge &a, Edge &b) {
//             return a.wt < b.wt;
//         });

//         DisjointSet ds(V);
//         int mstWeight = 0;

//         for (Edge &edge : edgeList) {
//             if (ds.find(edge.u) != ds.find(edge.v)) {
//                 ds.unionByRank(edge.u, edge.v);
//                 mstWeight += edge.wt;
//             }
//         }
//         return mstWeight;
//     }
// };