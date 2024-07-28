#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
 
        vector<string> reduced_grid(n / k);
        for (int i = 0; i < n; i += k) {
            string row = "";
            for (int j = 0; j < n; j += k) {
                row += grid[i][j];
            }
            reduced_grid[i / k] = row;
        }
 
        for (auto row : reduced_grid) {
            cout << row << endl;
        }
    }
    return 0;
}