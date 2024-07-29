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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> left, right;
        for (int i = 0; i < n; i++) {
            int coin;
            cin >> coin;
            if (coin < k) {
                left.push_back(coin);
            }
        }
        for (int i = 0; i < m; i++) {
            int coin;
            cin >> coin;
            if (coin < k) {
                right.push_back(coin);
            }
        }
        int ans = 0;
        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] <= k)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}