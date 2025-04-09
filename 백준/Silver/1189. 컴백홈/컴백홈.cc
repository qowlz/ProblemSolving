#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, k;
vector<vector<char>> arr;
vector<vector<bool>> visited;
vector<pair<int, int>> path;
int answer = 0;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void dfs(int y, int x, int d)
{
    if (d > k) return;

    if (y == 0 && x == c - 1 && d == k) // 종점이라면
    {
        // cout << "d: " << d << ", path:" << endl;
        // for (auto [y, x] : path)
        // {
        //     cout << "\t" << y << " : " << x << endl;
        // }

        answer++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

        if (arr[ny][nx] == 'T' || visited[ny][nx]) continue;

        visited[ny][nx] = true;
        path.push_back({ny, nx});
        dfs(ny, nx, d + 1);
        path.pop_back();
        visited[ny][nx] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> k;

    arr.assign(r, vector<char>(c, '\0'));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    visited.assign(r, vector<bool>(c, false));
    visited[r - 1][0] = true;

    dfs(r - 1, 0, 1);

    cout << answer;

    return 0;
}