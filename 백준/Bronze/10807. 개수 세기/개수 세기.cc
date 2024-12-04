#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int v;
    cin >> v;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == v) ans++;
    }

    cout << ans;


    return 0;
}