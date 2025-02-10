#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_T 5

int n;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    arr.assign(n + 2, {0,0});
    for (int i = 1; i <= n; i++)
    {
        int t, p;
        cin >> t >> p;
        arr[i] = {t, p};
    }

    vector<int> dp(n + MAX_T + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        ans = max(ans, dp[i]);
        dp[i] = ans;

        auto [t, p] = arr[i];
        dp[i + t] = max(dp[i + t], dp[i] + p);
    }

    cout << ans;

    return 0;
}