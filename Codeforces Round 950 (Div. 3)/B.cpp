#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> nums(n);
        for (auto& num : nums) {
            cin >> num;
        }
        int fVal = nums[f - 1];
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int>::iterator firstIndex = lower_bound(nums.begin(), nums.end(), fVal, greater<int>());
        vector<int>::iterator lastIndex = upper_bound(nums.begin(), nums.end(), fVal, greater<int>());
        int firstIdx = distance(nums.begin(), firstIndex) + 1;
        advance(lastIndex, -1);
        int lastIdx = distance(nums.begin(), lastIndex) + 1;
        if (firstIdx > k) {
            cout << "NO" << endl;
        }
        else if (lastIdx <= k) {
            cout << "YES" << endl;
        }
        else {
            cout << "MAYBE" << endl;
        }
    }
}