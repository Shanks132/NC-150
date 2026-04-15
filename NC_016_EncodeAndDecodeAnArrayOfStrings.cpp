#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string encode(vector<string>& strs) {
    string lengths;
    string encoded_str;
    for (int i = 0; i < strs.size(); i++) {
        // get string length
        lengths += to_string(strs[i].size()) + ',';
        // add the word to encoded string
        encoded_str += strs[i];
    }

    // cout << to_string(strs.size())+','+lengths+encoded_str;
    return to_string(strs.size()) + ',' + lengths + encoded_str;
}

vector<string> decode(string s) {
    vector<string> ans;

    string numberOfStr;
    int index = 0;
    for (char c : s) {
        if (c != ',') {
            numberOfStr += c;
        } else {
            break;
        }
        index++;
    }
    index++;
    int strsSize = stoi(numberOfStr);
    cout << "number of strings : " << strsSize;

    vector<int> strLengths;
    for (int i = 0; i < strsSize; i++) {
        string size;
        while (s[index] != ',') {
            size += s[index];
            index++;
        }
        index++;
        strLengths.push_back(stoi(size));
        cout << " size : " << size << endl;
        size = "";
    }
    cout << index << "s size - " << s.size();

    int wordCount = 0;
    for (int i = 0; i < strLengths.size(); i++) {
        int count = 0;
        string s1 = "";
        while (count < strLengths[i]) {
            s1 += s[index++];
            count++;
        }
        ans.push_back(s1);
    }
    // for(index;index<s.size();){
    //     string str1 ="";
    //     int length = strLengths[wordCount];
    //     int x = 0;
    //     while(x<length){
    //         str1 += s[index];
    //         x++;
    //         index++;
    //     }
    //     wordCount++;
    //     ans.push_back(str1);
    //     str1="";
    //     x=0;
    // }

    return ans;
}
