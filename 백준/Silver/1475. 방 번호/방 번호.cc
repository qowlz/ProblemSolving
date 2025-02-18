#include <iostream>
#include <vector>
using namespace std;

int n;

bool isSatisfy(int setNum)
{
    vector<int> arr(9, 0);
    for (int i = 0; i <= 8; i++)
        arr[i] = i == 6 ? 2 * setNum : setNum;

    int room = n;
    while(room)
    {
        int num = room % 10;
        room /= 10;

        num = num == 9 ? 6 : num;
        if (--arr[num] < 0)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    int left = 1, right = 1000;
    int ans = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isSatisfy(mid))
        {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}