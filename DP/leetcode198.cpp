#include <iostream>
using namespace std;
#include <vector>

int rob(int n, vector<int> &nums) {
    if(n >= nums.size()) return 0;

    int robbed = nums[n] + rob(n+2, nums);

    int notRobbed = rob(n+1, nums);

    return max(robbed, notRobbed);

}


int main() {
    int n = 4;
    vector<int> nums = {1, 2, 3, 1};
    // return rob(0, nums);
    cout << "Robbery max amount " << rob(0, nums) << endl;
    return 0;
}