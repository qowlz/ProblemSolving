#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, int>> arr(3);
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr.begin(), arr.end());

    int ansX = 0, ansY = 0;
    if (arr[0].first == arr[1].first)
    {
        ansX = arr[2].first;
        ansY = arr[1].second == arr[2].second ? arr[0].second : arr[1].second;
    }
    else
    {
        ansX = arr[0].first;
        ansY = arr[0].second == arr[2].second ? arr[1].second : arr[2].second;
    }

    cout << ansX << ' ' << ansY;

    return 0;
}