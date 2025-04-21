#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> selected;
int ans = INT_MAX;

void solve(int start)
{
    if (selected.size() == m)
    {
        int total = 0;
        for (auto home : houses)
        {
            // 선택된 치킨집 중에서 가장 가까운 곳을 찾기
            int dist = INT_MAX;
            for (auto idx : selected)
                dist = min(dist, abs(home.first - chickens[idx].first) + abs(home.second - chickens[idx].second));

            total += dist;
        }

        ans = min(ans, total);
    }

    for (int i = start; i < chickens.size(); i++)
    {
        selected.push_back(i);
        solve(i + 1);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;

            if (num == 1) houses.push_back({i, j});
            if (num == 2) chickens.push_back({i, j});
        }
    }

    solve(0);
    cout << ans;

    return 0;
}