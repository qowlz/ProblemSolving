#include <iostream>
#include <vector>
using namespace std;

long long s;

bool isLess(long long n)
{
    long long total = n * (n + 1) / 2;
    return total <= s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    long long left = 1, right = 100000, ans = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if (isLess(mid))
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}