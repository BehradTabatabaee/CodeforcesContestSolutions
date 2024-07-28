#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
 
        string a, b;
        cin >> a >> b;
 
        vector<vector<int>> a_prefix(n + 1, vector<int>(ALPHABET_SIZE, 0));
        vector<vector<int>> b_prefix(n + 1, vector<int>(ALPHABET_SIZE, 0));
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                a_prefix[i + 1][j] = a_prefix[i][j];
                b_prefix[i + 1][j] = b_prefix[i][j];
            }
            a_prefix[i + 1][a[i] - 'a']++;
            b_prefix[i + 1][b[i] - 'a']++;
        }
 
        while (q--) {
 
            int l, r;
            cin >> l >> r;
            l--; r--;
 
            vector<int> a_count(ALPHABET_SIZE, 0);
            vector<int> b_count(ALPHABET_SIZE, 0);
 
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                a_count[j] = a_prefix[r + 1][j] - a_prefix[l][j];
                b_count[j] = b_prefix[r + 1][j] - b_prefix[l][j];
            }
 
            int ans = 0;
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                ans += abs(a_count[j] - b_count[j]);
            }
            cout << ans / 2 << endl;
        }
    }
    return 0;
}