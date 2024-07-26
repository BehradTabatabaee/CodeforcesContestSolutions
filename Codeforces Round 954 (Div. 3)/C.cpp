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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ops(m);
        for (auto& op : ops) {
            cin >> op;
        }
        string c;
        cin >> c;
        sort(c.begin(), c.end());
        sort(ops.begin(), ops.end());
        unordered_map<int, char> mp;
        int i = 0;
        int prevOp = -1;
        for (auto op : ops) {
            if (prevOp != op && prevOp != -1) {
                mp[op - 1] = c[++i];
            }
            else
                mp[op - 1] = c[i];
            prevOp = op;
        }
        for (auto i : mp) {
            s[i.first] = i.second;
        }
        cout << s << endl;
    }
    return 0;
}