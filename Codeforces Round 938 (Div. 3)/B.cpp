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
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        map<int, int> nums;
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