#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    char seats[50];
    for (int i = 0; i < n; i++)
    {
        cin >> seats[i];
    }

    int holders = 1;
    int i = 0;
    while (i < n)
    {
        holders++;
        i = seats[i] == 'S' ? i + 1 : i + 2;
    }

    cout << min(holders, n);

    return 0;
}