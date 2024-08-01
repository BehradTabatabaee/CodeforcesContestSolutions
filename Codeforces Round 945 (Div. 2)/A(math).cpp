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
        if ((a + b + c) % 2 != 0) {
            cout << -1 << endl;
            continue;
        }
        else {
            int ans = 0;
            // since a is always the smallest, we can always have a draws
            // now, we have taken a draws, so the number of draws we can have is reduced by a
            ans += a;
            // we can optimally have b and c be equal so that we have b + c - a draws
            // but if that is not the case and b is smaller than c, then we can at most have b more draws
            ans += min(b, (b + c - a) / 2);
            cout << ans << endl;
        }
    }
    return 0;
}