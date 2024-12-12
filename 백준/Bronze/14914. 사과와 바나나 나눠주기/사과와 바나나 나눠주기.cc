#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int loop = min(a, b);
    for (int i = 1; i <= loop; i++)
    {
        if (a % i != 0 || b % i != 0) continue;

        cout << i << ' ' << a / i << ' ' << b / i << '\n';
    }


    return 0;
}