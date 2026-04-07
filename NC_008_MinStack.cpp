#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> st;
    vector<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min.size()==0){
            min.push_back(val);
        }
        else{
            int minimum = min[min.size()-1];
            if(val < minimum){minimum=val;}
            min.push_back(minimum);
        }
        st.push_back(val);       
    }
    
    void pop() {
        st.pop_back();
        min.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        return min[min.size()-1];
    }
};
