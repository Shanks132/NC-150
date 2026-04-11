#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int mid = 0;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                start = mid + 1;
            }
            if (nums[mid] > target) {
                end = mid - 1;
            }
        }
        return -1;
    }
};