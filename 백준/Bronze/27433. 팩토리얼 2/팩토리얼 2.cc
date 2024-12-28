#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    unsigned long long ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;

    cout << ans;


    return 0;
}