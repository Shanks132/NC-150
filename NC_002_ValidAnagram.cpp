#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool isAnagram(string s, string t) {
    unordered_map<char, int> s_letters;
    unordered_map<char, int> t_letters;
    for (auto ch : s) {
        s_letters[ch]++;
    }

    for (auto ch : t) {
        s_letters[ch]--;
    }
    for (auto letter : s_letters) {
        if (letter.second != 0) {
            return false;
        }
    }
    return true;
}