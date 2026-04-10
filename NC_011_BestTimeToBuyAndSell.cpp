#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int l = 0; 
        int r = 1;
        //select the highest selling price from the left
        while(r<prices.size()){
            int profit = prices[r]-prices[l];
            if(profit < 0){
               l = r;
               r = l+1;
               cout << "left moved to " << l<< endl;
            }
            else if(l<r && profit > ans){
                ans = profit;
                cout << "Max profit is "<< ans <<endl;
                r++;
            }
            else{r++;}
        }
        return ans;

    }
};
