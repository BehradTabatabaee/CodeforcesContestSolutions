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
        int n, k;
        cin >> n >> k;
        vector<int> diags;
        for (int i = n; i > 0; i--) {
            if (i == n) {
                diags.push_back(i);
            }
            else {
                diags.push_back(i);
                diags.push_back(i);
            }
        }
        int full = 0;
        for (auto diag : diags) {
            if (k <= 0) {
                break;
            }
            else {
                full++;
                k -= diag;
            }
        }
        cout << full << endl;
    }
}