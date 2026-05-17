#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxArea(vector<int>& heights) {
    int lBar = 0;
    int rBar = heights.size() - 1;
    int area;  // area = ( rBar - lBar ) * min(lBar,rBar);
    int maxArea = 0;
    while (lBar < rBar) {
        area = (rBar - lBar) * min(heights[lBar], heights[rBar]);
        maxArea = max(area, maxArea);
        if (heights[lBar] < heights[rBar]) {
            lBar++;
        } else {
            rBar--;
        }
    }
    return maxArea;
}