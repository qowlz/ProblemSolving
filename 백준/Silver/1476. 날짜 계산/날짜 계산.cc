#include <iostream>
#include <vector>
using namespace std;

#define MAX_E 15
#define MAX_S 28
#define MAX_M 19

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int e, s, m;
    cin >> e >> s >> m;

    int se = 1, ss = 1, sm = 1;
    int ans = 1;
    while (se != e || ss != s || sm != m)
    {
        se = se + 1 > MAX_E ? 1 : se + 1;
        ss = ss + 1 > MAX_S ? 1 : ss + 1;
        sm = sm + 1 > MAX_M ? 1 : sm + 1;

        ans++;
    }

    cout << ans;


    return 0;
}