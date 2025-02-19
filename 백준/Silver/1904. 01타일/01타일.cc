#include <iostream>
#include <vector>
using namespace std;

#define MOD 15746

int n;
vector<long long> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp.assign(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] % MOD + dp[i - 1] % MOD;
    }

    cout << dp[n] % MOD;

    return 0;
}