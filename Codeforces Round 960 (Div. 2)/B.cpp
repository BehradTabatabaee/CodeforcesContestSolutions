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
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n + 1);
        int it = 0;
        for (int i = y - 1; i >= 0; i--) {
            if (it % 2 == 0)
                arr[i] = -1;
            else
                arr[i] = 1;
            it++;
        }
        for (int i = y; i <= x; i++) {
            arr[i] = 1;
        }
        it = 0;
        for (int i = x + 1; i < n + 1; i++) {
            if (it % 2 == 0)
                arr[i] = -1;
            else
                arr[i] = 1;
            it++;
        }
        for (int i = 1; i < n + 1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}