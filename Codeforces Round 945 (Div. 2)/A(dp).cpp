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

vector<vector<vector<int>>> dp;

int howManyDraws(int a, int b, int c) {
    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }
    if (!((a > 0 && b > 0) || (a > 0 && c > 0) || (b > 0 && c > 0))) {
        return 0;
    }
    int draws = 0;
    if (a > 0 && b > 0) {
        draws = max(draws, 1 + howManyDraws(a - 1, b - 1, c));
    }
    if (a > 0 && c > 0) {
        draws = max(draws, 1 + howManyDraws(a - 1, b, c - 1));
    }
    if (b > 0 && c > 0) {
        draws = max(draws, 1 + howManyDraws(a, b - 1, c - 1));
    }
    return dp[a][b][c] = draws;
}

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

        dp.clear();
        dp.resize(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, -1)));
        
        cout << howManyDraws(a, b, c) << endl;
    }
    return 0;
}
