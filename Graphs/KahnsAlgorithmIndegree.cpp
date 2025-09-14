#include <iostream>
using namespace std;
#include<list>
#include<vector>
#include <stack>
#include <queue>


// Kahns ALGORITHM INDEGREE BFS

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V=6) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdges(int u, int v) {
        l[u].push_back(v);
    }

    void calIndegree(vector<int> &indeg) {
        for(int u=0; u<V; u++) {
            list<int> neighbors = l[u];
            for (int v : neighbors) {
                indeg[v]++;
            }
        }
    }

    void topoSort() { // khans algorithm
        vector<int> indeg(V, 0);
        calIndegree(indeg);
        queue<int>q;
        //0 indeg nodes -> startin point
        for(int i=0; i<V; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            list<int> neighbors = l[curr];
            for(int v : neighbors) {
                indeg[v]--;
                if(indeg[v] ==0) {
                    q.push(v);
                }
            }
        }
    }


};

int main() {
    //DAG
    Graph graph;
    
    graph.addEdges(5, 0);
    graph.addEdges(5, 2);
    graph.addEdges(2, 3);
    graph.addEdges(3, 1);
    graph.addEdges(4, 0);
    graph.addEdges(4, 1);

    graph.topoSort();

    return 0;
}