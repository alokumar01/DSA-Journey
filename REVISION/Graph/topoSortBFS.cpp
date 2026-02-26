// TOPOLOGICAL SORT(KAHN"S ALGORITHM) USING BFS(BREADTH FIRST SEARCH)
// DAG - DIRECTED ACYCLIC GRAPH (MEANS NO CYCLE)
#include <iostream>
using namespace std;
#include<list>
#include<vector>
#include <queue>

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdges(int u, int v) {
        l[u].push_back(v);
    }
    
    void calIndegree(vector<int>& indegree) {
        for(int u = 0; u < V; u++) {
            for (int neighbors : l[u]) {
                indegree[neighbors]++;
            }
        }
    }

    void topoSort() { // kahn's algorithm
        vector<int> indeg(V, 0);
        calIndegree(indeg);
        queue<int> q;

        //first push that node(vertices) whose indegree is zero
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        //bfs 
        while (!q.empty()) {
            int curr = q.front(); 
            q.pop();
            cout << curr << " ";
            for(int neighbor : l[curr]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

    }

};


int main() {
    Graph graph(6);
    graph.addEdges(5, 0);
    graph.addEdges(5, 2);
    graph.addEdges(2, 3);
    graph.addEdges(3, 1);
    graph.addEdges(4, 0);
    graph.addEdges(4, 1);

    graph.topoSort();

    return 0;
}