#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1000
#define MAX_COST 1e8

int n, m, s, e;
vector<pair<int, int>> arr[MAX_N + 1];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> ans;

void dijkstra()
{
    // 최단 거리 배열 초기화
    ans.assign(n + 1, MAX_COST);
    for (auto [to, c] : arr[s])
        ans[to] = min(ans[to], c);

    for (int i = 1; i <= n; i++)
        pq.push({ans[i], i});

    while (!pq.empty())
    {
        auto [acc, x] = pq.top();
        pq.pop();

        for (auto [to, c] : arr[x])
        {
            int total = acc + c;
            if (ans[to] <= total) continue;

            ans[to] = total;
            pq.push({total, to});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({to, cost});
    }

    cin >> s >> e;

    dijkstra();
    cout << ans[e];

    return 0;
}