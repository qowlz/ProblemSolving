#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());

    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * b[i];

    cout << ans;


    return 0;
}