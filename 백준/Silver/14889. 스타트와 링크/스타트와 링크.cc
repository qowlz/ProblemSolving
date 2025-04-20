#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;

vector<vector<int>> scores;
vector<int> selected;
int ans = INT_MAX;

// 뭔가 이 함수를 개선하면 좋을거같은데..
int getOtherScore()
{
    vector<int> other;
    for (int i = 0; i < n; i++)
    {
        if (find(selected.begin(), selected.end(), i) != selected.end()) continue;
        other.push_back(i);
    }

    int score = 0;
    for (auto i : other)
    {
        for (auto j : other)
        {
            score += scores[i][j];
        }
    }

    return score;
}

void solve(int start, int total)
{
    if (selected.size() == n / 2)
    {
        // cout << "selected: ";
        // for (auto x : selected)
        // {
        //     cout << x << ' ';
        // }
        // cout << endl;

        // cout << "total: " << total << endl;

        // auto other = getOtherScore();
        // cout << "other total: " << other << endl;

        ans = min(ans, abs(total - getOtherScore()));
        return;
    }

    for (int i = start; i < n; i++)
    {
        int add = 0;
        for (auto x : selected)
            add += scores[x][i] + scores[i][x];

        selected.push_back(i);
        solve(i + 1, total + add);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    scores.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> scores[i][j];
    }

    solve(0, 0);
    cout << ans;

    return 0;
}