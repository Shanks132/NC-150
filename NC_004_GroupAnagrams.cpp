#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> getWordHashMap(string s) {
    unordered_map<char, int> ump;
    for (char ch : s) {
        ump[ch]++;
    }
    return ump;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<unordered_map<char, int>> wordMapArr;
    for (int i = 0; i < strs.size(); i++) {
        wordMapArr.push_back(getWordHashMap(strs[i]));
    }

    for (int i = 0; i < strs.size(); i++) {
        vector<string> subAns = {strs[i]};
        if (strs[i] == "ABC") {
            continue;
        }
        for (int j = i + 1; j < strs.size(); j++) {
            if (strs[j] == "ABC") {
                continue;
            }
            if (wordMapArr[i] == wordMapArr[j]) {
                subAns.push_back(strs[j]);
                strs[j] = "ABC";
            }
        }
        ans.push_back(subAns);
    }
    return ans;
}
