#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a1, b1;
    cin >> a1 >> b1;

    int a2, b2;
    cin >> a2 >> b2;

    int num = b1 * a2 + b2 * a1;
    int den = b1 * b2;

    int isDivided = false;
    do
    {
        isDivided = false;
        int minimum = min(num, den);
        for (int i = minimum; i >= 2; i--)
        {
            if (num % i == 0 && den % i == 0)
            {
                num /= i;
                den /= i;
                isDivided = true;
                break;
            }
        }

    } while(isDivided);

    cout << num << ' ' << den;

    return 0;
}