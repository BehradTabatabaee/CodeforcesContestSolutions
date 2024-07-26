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
		vector<int> nums(3);
		for (auto& num : nums) {
			cin >> num;
		}
		int m = INT_MAX;
		for (int i = 0; i < 3; i++) {
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				if (nums[j] != nums[i]) {
					sum += abs(nums[j] - nums[i]);
				}
			}
			m = min(m, sum);
		}
		cout << m << endl;
	}
	return 0;
}