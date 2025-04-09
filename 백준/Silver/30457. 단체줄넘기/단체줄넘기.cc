#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        m[num]++;
    }

    int ans = 0;
    for (int i = 1; i <= 2; i++)
    {
        for (const auto& x : m)
        {
            if (m[x.first]-- >= 1) ans++;
        }
    }

    cout << ans;

    return 0;
}