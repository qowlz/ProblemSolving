#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, t;
vector<vector<int>> arr;

void bfs(vector<vector<bool>>& visited, int sy, int sx)
{
    visited[sy][sx] = true;

    queue<pair<int, int>> q;
    q.push({sy, sx});

    while (!q.empty())
    {
        auto [y, x] {q.front()};
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] || arr[ny][nx] < t) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    arr.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                int c;
                cin >> c;
                sum += c;
            }

            arr[i][j] = sum / 3;
        }
    }

    cin >> t;

    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] || arr[i][j] < t) continue;

            bfs(visited, i, j);
            ans++;
        }
    }

    cout << ans;

    return 0;
}