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
using namespace std;

int numOfGreater(vector<int>& a, int b) {
    int num = 0;
    for (auto i : a) {
        if (i >= b) {
            num++;
        }
    }
    return num;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto& n : nums) {
            cin >> n;
        }
        int flag = false;
        for (auto i : nums) {
            if ((numOfGreater(nums, i) - 1) % 2 == 0) {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO" << endl;
    }
    return 0;
}