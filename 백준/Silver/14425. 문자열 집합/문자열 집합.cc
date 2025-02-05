#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> s;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        s.insert(str);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;

        if (s.find(str) != s.end()) ans++;
    }

    cout << ans;


    return 0;
}