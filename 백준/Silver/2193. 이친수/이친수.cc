#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<long long>> cached;
int n;

long long solve()
{
    if (arr.size() >= n)
        return 1;

    int last = arr[arr.size() - 1];
    if (cached[arr.size()][last])
        return cached[arr.size()][last];

    long long total = 0;
    arr.push_back(0);
    total += solve();
    arr.pop_back();

    if (last == 0)
    {
        arr.push_back(1);
        total += solve();
        arr.pop_back();
    }

    return cached[arr.size()][last] = total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    cached.assign(n + 1, vector<long long>(2, 0));

    arr.push_back(1);
    cout << solve();

    return 0;
}