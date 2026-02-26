// #include <iostream>
// using namespace std;
// #include <bits/stdc++.h>

// class Graph{
//     int V;
//     list<int>*l;
// public:
//     Graph(int V) {
//         this->V = V;
//         l = new list<int> [V];
//     }

//     void addEdges(int u, int v) {
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     //dfs longest  path is a graph
//     int dfsHelper(int src, vector<bool> &vis) {
//        vis[src] = true;
       
//        for(int v : l[src]) {
//             if (!vis[v]) {
//                 dfsHelper(v, vis);
//             }
//         }
//     }

//     void dfs() {
//         vector<bool> vis(V, false);
//         for(int i = 0; i < V; i++) {
//             if(!vis[i]) {
//                 dfsHelper(i, vis);
//             }
//         }
//     }
// };

// int main() {
//     Graph graph(3);
//     graph.addEdges(1, 2);
//     graph.addEdges(2, 3);

//     graph.dfs();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

vector<int> adj[MAXN];
int farthestNode;
int maxDistance;

// DFS function
void dfs(int node, int parent, int distance) {
    
    // Update max distance and farthest node
    if (distance > maxDistance) {
        maxDistance = distance;
        farthestNode = node;
    }

    // Visit neighbours
    for (int neighbour : adj[node]) {
        if (neighbour != parent) {  // avoid going back
            dfs(neighbour, node, distance + 1);
        }
    }
}

int main() {
    int N;
    cin >> N;

    // Read edges
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 1: DFS from node 1 to find farthest node
    maxDistance = -1;
    dfs(1, -1, 0);

    int startNode = farthestNode;

    // Step 2: DFS from farthest node found
    maxDistance = -1;
    dfs(startNode, -1, 0);

    // maxDistance now stores diameter
    cout << maxDistance << endl;

    return 0;
}
