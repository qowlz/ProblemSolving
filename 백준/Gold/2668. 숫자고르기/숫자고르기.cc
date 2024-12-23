#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<bool> visited;
vector<int> arr;
vector<int> candidate;
set<int> answer;

void dfs(int start, int current)
{
    if (visited[current])
    {
        if (start == current) // detected cycle
        {
            for (auto& e : candidate)
            {
                answer.insert(e);
            }
        }

        return;
    }

    visited[current] = true;
    candidate.push_back(current);

    dfs(start, arr[current]);

    candidate.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        visited.assign(n + 1, false);
        dfs(i, i);
    }

    cout << answer.size() << '\n';

    for (auto& e : answer)
        cout << e << '\n';

    return 0;
}