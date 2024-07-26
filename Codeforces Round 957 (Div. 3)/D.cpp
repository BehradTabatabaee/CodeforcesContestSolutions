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
		string s;
		cin >> s;
		s.insert(s.begin(), 'L');
		s.append(1,'L');
		int position = 0;
		vector<int> logs;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') {
				logs.push_back(i);
			}
		}
		bool hasAns = true;
		int logPos = 1;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			if (s[i] != 'L') {
				if (s[i] == 'C') {
					cout << "NO" << endl;
					hasAns = false;
					break;
				}
				else if (k > 0) {
					k--;
					continue;
				}
				else {
					cout << "NO" << endl;
					hasAns = false;
					break;
				}
			}
			else if (logPos < logs.size() && i + m >= logs[logPos]) {
				i = logs[logPos++] - 1;
			}
			else if (logPos < logs.size() && i + m < logs[logPos]) {
				i += m - 1;
			}
		}
		if (hasAns) cout << "YES" << endl;
	}
	return 0;
}