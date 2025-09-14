#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool compare(pair<int, int> p1, pair<int, int> p2 ) {
    return p1.second < p2.second;
}

void maxLenChainPair(vector<int> &chain1, vector<int> &chain2) {
    int n = chain1.size();
    vector<pair<int, int>> pairs;

    for(int i=0; i < n; i++) {
        pairs.push_back(make_pair(chain1[i], chain2[i]));
    }

    int count = 1;
    int currEndChain = pairs[0].second;

    sort(pairs.begin(), pairs.end(), compare);

    for(int i=1; i<pairs.size(); i++) {
        if (pairs[i].first > currEndChain) {
            count++;
            currEndChain = pairs[i].second;
        }
    }

    cout << "Max  length of chain: " << count << endl;
}

int main() {
    vector<int> chain1 = {5, 39, 5, 27, 50};
    vector<int> chain2 = {24, 60, 28, 40, 90};

    maxLenChainPair(chain1, chain2);

    return 0;
}