#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

bool isValid(string s) {
    if (s.length() == 1) {
        return false;
    }
    stack<char> openingBraces;

    for (char ch : s) {
        if (ch == '[' || ch == '{' || ch == '(') {
            openingBraces.push(ch);
        }
        if (ch == ']') {
            if (openingBraces.empty() || openingBraces.top() != '[') {
                return false;
            } else {
                openingBraces.pop();
            }
        }
        if (ch == '}') {
            if (openingBraces.empty() || openingBraces.top() != '{') {
                return false;
            } else {
                openingBraces.pop();
            }
        }
        if (ch == ')') {
            if (openingBraces.empty() || openingBraces.top() != '(') {
                return false;
            } else {
                openingBraces.pop();
            }
        }
    }
    if (!openingBraces.empty()) {
        return false;
    }
    return true;
}