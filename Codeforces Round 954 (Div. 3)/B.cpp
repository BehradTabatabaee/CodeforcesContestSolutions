#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> mat(n, vector<int>(m));
		vector<int> matArr;
		for (auto& i : mat) {
			for (auto& j : i) {
				cin >> j;
				matArr.push_back(j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vector<int> neighbours;
				if (i - 1 >= 0)
					neighbours.push_back(mat[i - 1][j]);
				if (i + 1 < n)
					neighbours.push_back(mat[i + 1][j]);
				if (j - 1 >= 0)
					neighbours.push_back(mat[i][j - 1]);
				if (j + 1 < m)
					neighbours.push_back(mat[i][j + 1]);
				mat[i][j] = min(mat[i][j], *max_element(neighbours.begin(), neighbours.end()));
			}
		}
		for (auto i : mat) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}