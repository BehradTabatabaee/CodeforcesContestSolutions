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
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        int ans = 0;
        if (b < 2 * a) {
            ans = ((n / 2) * b) + ((n % 2) * a);
        }
        else {
            ans = n * a;
        }
        cout << ans << endl;
    }
    return 0;
}