#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Row {
public:
    int count ;
    int idx;

    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const {
        if (this->count == obj.count) {
            return this->idx > obj.idx;
        }
        return this->count > obj.count; // min
    }
};


void weakestSoldier(vector<vector<int>> matrix, int K) {
    vector<Row> rows;

    for(int i=0; i<matrix.size(); i++) {
        int count = 0;
        for(int j=0; j<matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end()); 

    for(int i=0; i<K; i++) {
        cout << "Row " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                {1, 1, 1, 1},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}};

    weakestSoldier(matrix, 2);
    return 0;
}