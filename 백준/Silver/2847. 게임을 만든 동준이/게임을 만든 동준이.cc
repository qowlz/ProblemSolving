#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int least = *arr.rbegin() - 1;
    int ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (least <= arr[i])
        {
            ans += abs(arr[i] - least);
            least--;
        }
        else
            least = arr[i] - 1;
    }

    cout << ans;


    return 0;
}