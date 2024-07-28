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
        int a, b, c;
        cin >> a >> b >> c;
        int tents = 0;
        tents += a;
        int exTents = (b / 3) + ((b % 3) != 0);
        if ((b + c) < (exTents * 3)) {
            cout << -1 << endl;
            continue;
        }
        tents += exTents;
        tents += (((b + c) - (exTents * 3)) / 3) + (((b + c) - (exTents * 3)) % 3 != 0);
        cout << tents << endl;
    }
    return 0;
}