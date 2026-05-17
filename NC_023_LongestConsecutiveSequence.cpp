#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        numMap[nums[i]]++;
    }
    int len = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        len = 1;
        int curr = nums[i];
        if (numMap[curr - 1] > 0) {
            continue;
        }
        while (numMap[++curr] > 0) {
            len++;
        }
        if (len == nums.size()) {
            return len;
        }
        ans = max(ans, len);
    }
    return ans;
}