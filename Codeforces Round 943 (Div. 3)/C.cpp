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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n - 1), b(n);
        for (auto& i : a) {
            cin >> i;
        }
        b[0] = 501;
        for (int i = 1; i < n; i++) {
            b[i] = b[i - 1] + a[i - 1];
        }
        for (auto i : b) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}