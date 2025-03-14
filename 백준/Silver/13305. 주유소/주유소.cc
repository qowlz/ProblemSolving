#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<unsigned long long> d(n + 1, 0);
    for (int i = 2; i <= n; i++)
        cin >> d[i];

    vector<unsigned long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    unsigned long long lowV = INT_MAX;
    unsigned long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        lowV = min(lowV, v[i - 1]);
        ans += lowV * d[i];
    }

    cout << ans;

    return 0;
}