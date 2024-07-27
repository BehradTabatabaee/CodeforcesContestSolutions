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
// THE TEST CASES HAVE BEEN DESIGNED TO MAKE IT SO THAT 
// THE REGULAR HASH TABLE (WITH THE DEFAULT HASH FUNCTION)
// GETS COLLISIONS REGULARLY, SO IT GETS A TLE
// ROFL:))
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
        int n, c, d;
        cin >> n >> c >> d;
        unordered_map<int, int, custom_hash> nums;
        int min = INT_MAX;
        for (int i = 0; i < n * n; i++) {
            int num;
            cin >> num;
            nums[num]++;
            if (num <= min)
                min = num;
        }
        vector<int> mat(n * n);
        mat[0] = min;
        nums[min--];
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (nums[mat[i - 1] + d] > 0) {
                mat[i] = mat[i - 1] + d;
                nums[mat[i - 1] + d]--;
            }
            else {
                cout << "NO" << endl;
                flag = false;
                goto end;
            }
        }
        for (int i = n; i < n * n; i++) {
            if (nums[mat[i - n] + c] > 0) {
                mat[i] = mat[i - n] + c;
                nums[mat[i - n] + c]--;
            }
            else {
                cout << "NO" << endl;
                flag = false;
                goto end;
            }
        }
        end:
        if (flag)
            cout << "YES" << endl;
    }
    return 0;
}