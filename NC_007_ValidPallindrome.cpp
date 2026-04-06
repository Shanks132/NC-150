#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool checkAlphaNumeric(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9')) {
        return true;
    }

    return false;
}
bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start < end) {
        if (checkAlphaNumeric(s[start]) == false) {
            cout << s[start];
            start++;
            continue;
        } else if (checkAlphaNumeric(s[end]) == false) {
            end--;
            continue;
        } else {
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else if (tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
            }
        }
    }
    return true;
}