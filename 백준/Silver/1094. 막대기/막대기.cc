#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x;
    cin >> x;

    int ans = 0;
    int small = 64;
    while(x)
    {
        if (small <= x)
        {
            x -= small;
            ans++;
        }
        else
            small /= 2;

    }

    cout << ans;

    return 0;
}