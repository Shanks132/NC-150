#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
  for (int i = 0; i < nums.size(); i++)
  {
    int currentNum = nums[i];
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (currentNum + nums[j] == target)
      {
        return {i, j};
      }
    }
  }
  // above is the brute force
  //  can be done with a hash map
  /*
  step 1 - create a hash map of elements
  step 2 - now go through each element once
          check if (target - current element) exists in hash table.
  step 3 - now return the indices of the same element
  */
}