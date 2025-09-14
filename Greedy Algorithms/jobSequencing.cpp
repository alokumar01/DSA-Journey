#include <iostream>
using namespace std;
#include<bits/stdc++.h>

// bool compare(pair<int, int> p1, pair<int, int> p2) {
//     return p1.second > p2.second;
// }

// void jobSequenceProfit(vector<int>&days, vector<int>& profit) {
//     int n = days.size();
//     vector<pair<int, int>> jobs;

//     for(int i=0; i<n; i++) {
//         jobs.push_back(make_pair(days[i], profit[i]) );
//     } 

//     int totalProfit = jobs[0].second;
//     int safeDeadline = 2;

//     sort(jobs.begin(), jobs.end(), compare);
//     for(int i=1; i<jobs.size(); i++) {
//         if (jobs[i].first >= safeDeadline) {
//             totalProfit += jobs[i].second;
//             safeDeadline++;
//         }
//     }

//     cout << "Max Profit: " << totalProfit << endl;
// }

// int main() {
//     vector<int>days = {4, 1, 1, 1};     
//     vector<int>profit = {20, 10, 40, 30};
//     jobSequenceProfit(days, profit);
//     return 0;
// }

// -----------------------ABOVE IS ONLY BASED ON PROFIT MEANS RETURN THE PROFIT----------------- in same question variants for tracking the order we use the oops concept

class Jobs {
public:
    int idx;
    int deadline;
    int profit;

    Jobs(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

void jobSequenceProfit(vector<pair<int, int>>& pairs) {
    int n = pairs.size();
    vector<Jobs> jobs;

    for(int i=0; i<n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second );
    }

    sort(jobs.begin(), jobs.end(), [](Jobs &a, Jobs &b) {
        return a.profit > b.profit; //desc on profit
    });
    
    cout << "Selecting Job " << jobs[0].idx << endl;
    int totalProfit = jobs[0].profit;
    int safeDeadline = 2;

    // sort(jobs.begin(), jobs.end(), );

    for(int i=1; i<n; i++) {
        if (jobs[i].deadline >= safeDeadline) {
            cout << "Selecting Job " << jobs[i].idx << endl;
            totalProfit += jobs[i].profit;
            safeDeadline++;
        }
    }

    cout << "Max Profit: " << totalProfit << endl;
}


int main() {
    vector<int>days = {4, 1, 1, 1};     
    vector<int>profit = {20, 10, 40, 30};
    vector<pair<int, int>> pairs;
    int n = 4;

    for(int i=0; i<n; i++) {
        pairs.push_back(make_pair(days[i], profit[i]) );
    } 

    jobSequenceProfit(pairs);
    return 0;
}