#include <iostream>
using namespace std;
#include <vector>

class Disjoint {
    vector<int> parent;
    vector<int> rank;
public:
    Disjoint(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for(int i = 0; i < size; i++) {
            parent[i] = i; // Initially, every node is its own parent.
        }
    }

    // Find the representative (leader) of the set with path compression.
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]); // Compress path for faster future queries.
    }

    // Merge two sets using union by rank to keep tree shallow.
    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) {
            return; // Already in the same set, nothing to merge.
        }

        if (rank[parA] == rank[parB]) {
            parent[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB] ) {
            parent[parB] = parA;
        } else {
            parent[parA] = parB;
        }
    }

};


int main() {
    Disjoint dj(6);
    
    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl;
    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0, 4);
    return 0;
}
