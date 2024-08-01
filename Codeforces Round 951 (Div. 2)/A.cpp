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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto& num : nums) {
            cin >> num;
        }
        int minSubarrayElement = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int currentSubarrayMax = nums[i];
            for (int j = i + 1; j < n; j++) {
                currentSubarrayMax = max(currentSubarrayMax, nums[j]);
                minSubarrayElement = min(minSubarrayElement, currentSubarrayMax);
            }
        }
        cout << minSubarrayElement - 1 << endl;
    }
    return 0;
}