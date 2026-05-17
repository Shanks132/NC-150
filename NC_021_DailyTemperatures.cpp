#include <iostream>
#include <vector>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size(), 0);
    result[temperatures.size() - 1] = 0;
    for (int i = 0; i < temperatures.size(); i++) {
        int currTemp = temperatures[i];
        int days = 0;
        for (int j = i + 1; j < temperatures.size(); j++) {
            if (temperatures[j] > currTemp) {
                days++;
                result[i] = days;
                break;
            } else {
                days++;
            }
        }
    }
    return result;
}
