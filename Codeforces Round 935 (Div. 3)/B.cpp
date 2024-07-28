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
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, m;
        cin >> a >> b >> m;
        int withEachOther = lcm(a, b);
        int howManyA = (((withEachOther + m) - (withEachOther)) / a) + 1;
        int howManyB = (((withEachOther + m) - (withEachOther)) / b) + 1;
        cout << howManyA + howManyB << endl;
    }
    return 0;
}