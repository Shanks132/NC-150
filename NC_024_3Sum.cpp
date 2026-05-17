#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> uniqueAns;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        int x = 0;
        int y = nums.size() - 1;
        while (x < y) {
            if (x == i) {
                x++;
                continue;
            }
            if (y == i) {
                y--;
                continue;
            }
            int sum = nums[x] + nums[y];
            if (sum == -curr) {
                vector<int> ansSet;
                ansSet.push_back(nums[x++]);
                ansSet.push_back(nums[y--]);
                ansSet.push_back(nums[i]);
                sort(ansSet.begin(), ansSet.end());
                uniqueAns.insert(ansSet);
                continue;
            }
            if (sum + curr > 0) {
                y--;
                continue;
            }
            if (sum + curr < 0) {
                x++;
                continue;
            }
        }
    }
    for (auto e : uniqueAns) {
        ans.push_back(e);
    }
    return ans;
}