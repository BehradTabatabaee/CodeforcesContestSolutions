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

// custom hash function to escape unordered_map blowup
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// function to check whether a given number is a power of 2 or not
bool isPowerOfTwo(int n) {
    return (n && !(n & (n - 1)));
}

// decimal number to an array of boolean (bits) conversion
vector<bool> decimalToBinary(int n) {
    if (n == 0) {
        return {0};
    }
    int numberOfBits = log2(n) + 1;
    vector<bool> ans(numberOfBits, 0);
    for (int i = numberOfBits - 1; i >= 0; i--) {
        if ((n & (1 << i)) == (1 << i)) {
            ans[i] = 1;
        }
    }   
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {

    }
    return 0;
}