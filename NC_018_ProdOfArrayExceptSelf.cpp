#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1;
    vector<int> ans(nums.size(), 0);
    int numberOfZeroes = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            product = product * nums[i];
            // cout << " "<<product;
        } else {
            numberOfZeroes++;
            cout << "Zero detected";
            if (numberOfZeroes == 2) {
                return ans;
            }
        }
    }
    if (numberOfZeroes == 1) {
        cout << "There is a zero";
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                ans[i] = 0;
            } else {
                ans[i] = product;
            }
        }

    } else {
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = product / nums[i];
            cout << ans[i];
        }
    }
    return ans;
}
