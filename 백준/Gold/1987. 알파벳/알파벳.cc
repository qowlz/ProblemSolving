#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int r, c;
vector<vector<char>> board;
bool visited[26];
int ans = 1;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x, int acc)
{
    ans = max(ans, acc);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <= 0 || ny > r || nx <= 0 || nx > c) continue;

        int idx = board[ny][nx] - 'A';
        if (visited[idx]) continue;

        visited[idx] = true;

        dfs(ny, nx, acc + 1);

        visited[idx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    board.assign(r + 1, vector<char>(c + 1, '\0'));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> board[i][j];
        }
    }

    visited[board[1][1] - 'A'] = true;

    dfs(1, 1, 1);
    cout << ans;

    return 0;
}