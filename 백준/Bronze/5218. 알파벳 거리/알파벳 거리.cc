#include <iostream>
#include <vector>
using namespace std;

int getLen(char x, char y)
{
    if (y >= x)
        return y - x;
    else
        return (y + 26) - x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        cout << "Distances: ";
        for (int i = 0; i < a.length(); i++)
        {
            cout << getLen(a[i], b[i]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}