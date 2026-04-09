#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> tokenStack;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" &&
            tokens[i] != "/") {
            tokenStack.push(stoi(tokens[i]));
        } else {
            int num1 = tokenStack.top();
            tokenStack.pop();
            int num2 = tokenStack.top();
            tokenStack.pop();
            int ans;
            if (tokens[i] == "+") {
                ans = num2 + num1;
            }
            if (tokens[i] == "-") {
                ans = num2 - num1;
            }
            if (tokens[i] == "*") {
                ans = num2 * num1;
            }
            if (tokens[i] == "/") {
                ans = num2 / num1;
            }
            tokenStack.push(ans);
        }
    }
    return tokenStack.top();
}

