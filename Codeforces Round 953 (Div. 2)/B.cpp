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
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        int profit = 0;
        if (b <= a) {
            cout << n * a << endl;
            continue;
        }
        int howMany = min(b - a, n);
        // sum of a continuous series :
        // (n + 1) * n / 2
        // (startNum + endNum) * (numCount / 2)
        // we have (numCount / 2) elements whose sum is equal to (start + end)
        profit += (b - howMany + 1 + b) * howMany / 2;
        profit += (n - howMany) * a;
        cout << profit << endl;
    }
    return 0;
}