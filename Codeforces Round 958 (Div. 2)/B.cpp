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
        string s = "";
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (i == 0)
                s += c;
            else {
                if (c == '0' && s[s.size() - 1] == '0') {
                    continue;
                }
                else {
                    s += c;
                }
            }
        }
        int ones = 0, zeros = 0;
        for (auto i : s) {
            if (i == '0')
                zeros++;
            else
                ones++;
        }
        if (ones > zeros)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}