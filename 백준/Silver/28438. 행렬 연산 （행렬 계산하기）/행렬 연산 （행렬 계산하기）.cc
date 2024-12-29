#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> row(n + 1, 0);
    vector<long long> col(m + 1, 0);
    while(q--)
    {
        int cmd, rc, v;
        cin >> cmd >> rc >> v;

        if (cmd == 1)
            row[rc] += v;
        else
            col[rc] += v;
    }

    vector<vector<long long>> ans(n + 1, vector<long long>(m + 1, 0));

    // 행 먼저
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans[i][j] += row[i];
            ans[i][j] += col[j];
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}