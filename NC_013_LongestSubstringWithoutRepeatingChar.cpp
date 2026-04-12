#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hm;
    int l = 0;
    int r = 0;
    int ans = 0;
    int length = 0;
    while (r < s.size()) {
        if (hm[s[r]] == 0) {
            // cout << "unique letter "<< s[r];
        } else {
            // cout << "letter "<< s[r] << " has repeated"<< endl;
            while (hm[s[r]] != 0) {
                hm[s[l]]--;
                length--;
                l++;
            }
            // cout<<s[r]<< "was removed\n";
        }
        hm[s[r]]++;
        length++;
        if (length > ans) {
            ans = length;
        }
        r++;
        // cout <<" length = "<< length << " maxL " << ans << endl;
    }
    return ans;
}
}
;
