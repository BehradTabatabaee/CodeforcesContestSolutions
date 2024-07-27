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
 
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max = 1, maxNum = 1;        
        for (int i = n - 1; i > 1; i--) {
            int ans = gcd(i, n) + i;
            if (ans > max) {
                max = ans;
                maxNum = i;
            }
        }
        cout << maxNum << endl;
    }
    return 0;
}