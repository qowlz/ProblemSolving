#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // K~N 번째 출력
    for (int i = k - 1; i < n; i++)
    {
        cout << s[i];
    }

    int reverseCount = n - k + 1;
    if (reverseCount % 2)
    {
        // K - 1 ~ 1번째 역순 출력
        for (int i = k - 2; i >= 0; i--)
        {
            cout << s[i];
        }
    }
    else
    {
        // 1 ~ K - 1 번째 정순 출력
        for (int i = 0; i <= k - 2; i++)
        {
            cout << s[i];
        }
    }


    return 0;
}