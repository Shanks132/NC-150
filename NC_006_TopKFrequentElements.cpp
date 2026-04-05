#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hashMap;
    vector<int> ans(k, -1);

    for (int i = 0; i < nums.size(); i++) {
        hashMap[nums[i]]++;
    }

    for (int i = 0; i < k; i++) {
        int nHighestFreqNum = nums[0];
        int nHighestFreq = -1;
        for (auto e : hashMap) {
            if (e.second > nHighestFreq) {
                cout << "num " << e.first << "freq " << e.second << "\n";
                nHighestFreq = e.second;
                nHighestFreqNum = e.first;
            }
        }
        cout << "One element added to ans" << endl;
        ans[i] = nHighestFreqNum;
        hashMap[nHighestFreqNum] = -1;
    }
    return ans;
}
