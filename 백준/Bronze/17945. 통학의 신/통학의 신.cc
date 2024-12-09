#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int b, c;
    cin >> b >> c;

    b *= 2;

    int s1 = (-b - (int)sqrt(b * b - 4 * c)) / 2;
    int s2 = (-b + (int)sqrt(b * b - 4 * c)) / 2;

    if (s1 == s2)
        cout << s1;
    else
        cout << s1 << ' ' << s2;

    return 0;
}