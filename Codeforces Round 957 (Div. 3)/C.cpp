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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> nums;
		for (int i = n; i > m; i--) {
			nums.push_back(i);
		}
		for (int i = 1; i <= m; i++) {
			nums.push_back(i);
		}
		for (auto i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}