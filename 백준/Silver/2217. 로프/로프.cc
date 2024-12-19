#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (n - i));
    }

    cout << ans;


    return 0;
}