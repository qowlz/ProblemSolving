#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int m;
vector<int> arr;

bool satisfy(int maximum)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += min(arr[i], maximum);

    return sum <= m;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    arr.assign(n, 0);
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }

    cin >> m;

    int lo = 0;
    int ans = INT_MIN;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (satisfy(mid))
        {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << ans;

    return 0;
}