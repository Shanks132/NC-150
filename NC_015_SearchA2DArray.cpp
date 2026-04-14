#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;

    int s1 = 0;
    int e1 = m;
    int s2 = 0;
    int e2 = n;
    int mid1 = 0;

    while (s1 <= e1) {
        mid1 = (s1 + e1) / 2;
        cout << "s1 = " << s1 << endl;
        cout << "e1 = " << e1 << endl;

        if (target > matrix[mid1][n]) {
            s1 = mid1 + 1;
            continue;
        } else if (target < matrix[mid1][0]) {
            e1 = mid1 - 1;
            continue;
        } else {
            cout << "The element is in row :" << mid1 << endl;
            break;
        }
    }
    while (s2 <= e2) {
        int mid2 = (s2 + e2) / 2;
        if (target > matrix[mid1][mid2]) {
            s2 = mid2 + 1;
        } else if (target < matrix[mid1][mid2]) {
            e2 = mid2 - 1;
        } else {
            return true;
        }
    }
    return false;
}
