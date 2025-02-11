#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<bool>> arr(100 + 1, vector<bool>(100 + 1, false));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int i = y; i < y + 10; i++)
        {
            for (int j = x; j < x + 10; j++)
            {
                arr[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (arr[i][j]) ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}