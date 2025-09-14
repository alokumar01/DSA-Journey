#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

int maxActivity(vector<int>start, vector<int> end) {
    // sort on end time
    // A0 means select first 
    int count = 1;
    int currEndTime = end[0];

    for(int i=1; i<start.size(); i++) {
        if(start[i] >= currEndTime) {
            count++;
            currEndTime = end[i];
        }
    }
    return count;
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second; // ascending -end
}

int main() {
    // vector<int> start = {1, 3, 0, 5, 8, 5};
    // vector<int> end =   {2, 4, 6, 7, 9, 9};
    
    // cout << "MAXIMUM ACTIVITY: " << maxActivity(start, end) << endl;

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end =   {2, 4, 6, 7, 9, 9};

    vector<pair<int, int>> activity(3, make_pair(0, 0));
    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    sort(activity.begin(), activity.end(), compare);
    
    cout << "--------SORTED---------\n";
    for(int i=0; i<activity.size(); i++) {
        cout << "A" << i << " : " << activity[i].first << "," << activity[i].second << endl;
    }
    
    return 0;
}
