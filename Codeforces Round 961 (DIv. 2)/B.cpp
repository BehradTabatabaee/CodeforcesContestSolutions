#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

set<pair<long long, long long>, greater<>> petals;
map<pair<long long, pair<int, long long>>, long long> dp;

long long solve(long long money, int round = 1, set<pair<long long, long long>, greater<>>::iterator it = petals.begin(), long long prevPetal = -1) {
    if (it == petals.end()) return 0;

    long long petalValue = it->first;
    long long count = it->second;

    if (prevPetal != -1 && abs(prevPetal - petalValue) > 1) return 0;

    auto state = make_pair(money, make_pair(round, prevPetal));
    if (dp.find(state) != dp.end()) return dp[state];

    if (round == 2) {
        long long buyable = min(count, money / petalValue);
        return dp[state] = petalValue * buyable;
    }

    long long m = 0;
    for (long long i = 0; i <= min(count, money / petalValue); i++) {
        auto next_it = it;
        advance(next_it, 1);
        long long currentPetals = i * petalValue;
        if (i == 0) {
            m = max(m, solve(money, round, next_it, prevPetal));
        }
        else if (money >= currentPetals) {
            m = max(m, solve(money - currentPetals, round + 1, next_it, petalValue) + currentPetals);
        }
    }
    return dp[state] = m;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        petals.clear();
        dp.clear();

        map<long long, long long> petalCounts;
        for (long long i = 0; i < n; i++) {
            long long petal;
            cin >> petal;
            petalCounts[petal]++;
        }

        for (const auto& p : petalCounts) {
            petals.insert({ p.first, p.second });
        }

        cout << solve(m) << endl;
    }
    return 0;
}