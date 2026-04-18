
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) {
    int e = 0;
    int s = 1;
    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] > e) {
            e = piles[i];
        }
    }
    int ans = e;
    while (s <= e) {
        int hoursTaken = 0;
        int currRate = (s + e) / 2;

        for (int i = 0; i < piles.size(); i++) {
            // hoursTaken += ceil((piles[i]/currRate) +
            // (piles[i]%currRate));
            hoursTaken += piles[i] / currRate;
            if (piles[i] % currRate > 0) {
                hoursTaken++;
            }
        }
        cout << " \nhours taken - " << hoursTaken << " @ " << currRate;
        if (hoursTaken <= h) {
            if (ans > currRate) {
                ans = currRate;
            }
            cout << "Reducing current rate and checking \n";
            e = currRate - 1;
            cout << s << " " << e;
        } else {
            s = currRate + 1;
        }
    }
    return ans;
}
