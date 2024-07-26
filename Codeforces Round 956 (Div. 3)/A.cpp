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
        int a, b, c;
        cin >> a >> b >> c;
        nums[0] = a;
        nums[1] = b;
        nums[2] = c;
        sort(nums.begin(), nums.end());
        int turns = 5;
        while (turns--) {
            vector<int>::iterator num = min_element(nums.begin(), nums.end());
            (*num)++;
        }
        int multiply = 1;
        for (auto i : nums) {
            multiply *= i;
        }
        cout << multiply << endl;
    }
    return 0;
}