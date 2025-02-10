#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    arr.assign(n + 1, {0,0});
    for (int i = 1; i <= n; i++)
    {
        int t, p;
        cin >> t >> p;
        arr[i] = {t, p};
    }

    vector<int> dp(n + 2, 0);
    int ans = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        dp[i] = ans;
        for (int j = i - 1; j >= 1; j--)
        {
            auto [t, p] = arr[j];
            if (j + t == i)
            {
                dp[i] = max(dp[i], dp[j] + p);
                ans = max(ans, dp[i]);
            }
        }

        // cout << "dp[" << i << "]: " << dp[i] << endl;
    }

    cout << ans;

    return 0;
}