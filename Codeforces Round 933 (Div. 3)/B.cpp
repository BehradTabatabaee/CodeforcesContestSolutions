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
        vector<int> arr(n);
        for (auto& i : arr) {
            cin >> i;
        }
        for (int i = 0; i < n - 2; i++) {
            if (arr[i] < 0)
                break;;
            int num = arr[i];
            arr[i] -= num;
            arr[i + 1] -= 2 * num;
            arr[i + 2] -= num;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
        } 
    }
    return 0;
}