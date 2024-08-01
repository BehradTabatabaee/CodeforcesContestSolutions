#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <limits.h>
#include <numeric>
#include <chrono>
using namespace std;

// custom hash function to escape unordered_map blowup
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        // each round adds a score of 2, so if the sum of scores is not divisable by 2
        // there is no valid combination
        if ((a + b + c) % 2 != 0) {
            cout << -1 << endl;
            continue;
        }
        // since the values are sorted in the input, we can always have a draws, so we make them
        int draws = a;
        // now we want to find the pairs who drew with a. the optimal selection algorithm is as follows:
        // we want b and c to be as close to each other as possible, since by being close they can make more draws
        // for example if b is 1 and c is 3, we can have at most 1 draw, but if they are both 2, we can have 2 draws
        // so, we make them draw with a based on which one is bigger so that we can make them closer to each other
        for (int i = 0; i < a; i++) {
            if (c > b) {
                c--;
            }
            else {
                b--;
            }
        }
        // now, we have successfully drawn a times. so we have to find the amount of draws we can have between b and c
        // if they are equal, then we can have them draw all of their scores, but if they are not, we can have at most min(b, c) draws
        if (b == c) {
            draws += b;
        }
        else {
            draws += min(b, c);
        }
        cout << draws << endl;
    }
    return 0;
}