#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        vector<char> needs = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
        unordered_multiset<char> problems;
        for (int i = 0; i < n; i++) {
            char problem;
            cin >> problem;
            problems.insert(problem);
        }
        for (auto c : needs) {
            if (problems.count(c) < m) {
                ans += m - problems.count(c);
            }
        }
        cout << ans << endl;
    }
}