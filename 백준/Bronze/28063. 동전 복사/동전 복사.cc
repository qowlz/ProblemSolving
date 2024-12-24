#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x, y, ans = 4;
    cin >> n >> x >> y;

    if (x == 1) ans--;
    if (x == n) ans--;
    if (y == 1) ans--;
    if (y == n) ans--;

    cout << ans;


    return 0;
}