#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++) {
        // cout << i <<" added to count of hashMap"<<endl;
        hashMap[nums[i]]++;
    }
    for (auto i : hashMap) {
        // cout << "count of " << i.first << " is " << i.second<<endl;
        if (i.second > 1) {
            return true;
        }
    }
    return false;
}