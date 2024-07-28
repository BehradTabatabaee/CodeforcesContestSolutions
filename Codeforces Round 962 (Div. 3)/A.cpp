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
        int n;
        cin >> n;
        int remaining = n % 4;
        int fourLegs = n / 4;
        int twoLegs = remaining / 2;
        cout << fourLegs + twoLegs << endl;
    }
    return 0;
}