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
        int n;
        cin >> n;
        vector<int> nums(n);
        int sum = 0;
        for (auto& num : nums) {
            cin >> num;
            sum += num;
        }
        if (sum % 3 == 0)
            cout << 0 << endl;
        else {
            bool flag = true;
            for (auto i : nums) {
                if ((sum - i) % 3 == 0) {
                    cout << 1 << endl;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if ((sum + 1) % 3 == 0) {
                    cout << 1 << endl;
                }
                else {
                    cout << 2 << endl;
                }
            }
        }
    }
    return 0;
}