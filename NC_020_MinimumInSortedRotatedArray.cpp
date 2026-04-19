#include <iostream>
#include <vector>
using namespace std;


int findMin(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = (s + e) / 2;
    if (arr[0] < arr[e]) {
        return arr[0];
    }
    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else if (arr[mid] < arr[e]) {
            e = mid;
        }
        mid = (s + e) / 2;
        cout << mid << endl;
    }
    return arr[mid];
}
