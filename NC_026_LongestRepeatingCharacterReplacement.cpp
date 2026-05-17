#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int characterReplacement(string s, int k) {
    int l = 0;
    int r = 0;
    int ans = 0;
    unordered_map<char, int> hashMap;
    hashMap[s[0]]++;
    while (r < s.size()) {
        int totalLetters = 0;
        int highestF = 0;
        for (auto e : hashMap) {
            // find total letters
            totalLetters += e.second;
            // find freq of most frequent letter
            highestF = max(highestF, e.second);
        }
        // check if curr str is valid
        if (totalLetters - highestF <= k) {
            // if valid change the answer
            cout << "moving r++ \n";
            ans = max(totalLetters, ans);
            r++;
            hashMap[s[r]]++;
        } else {
            cout << " moving l++ \n";
            hashMap[s[l++]]--;
        }
    }
    return ans;
}