#include <iostream>
#include <unordered_set>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int lowerBound(int x)
{
    int left = 0, right = n - 1;
    int idx = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] >= x)
        {
            idx = min(idx, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int last = INT_MAX;
    pair<int, int> ans;
    for (int i = 0; i < n; i++)
    {
        int idx = lowerBound(-arr[i]);

        // idx 뒤에 정답 후보가 존재하니 둘다 비교 가능한 경우, 비교하기
        int diff = abs(arr[i] + arr[idx]);
        if (idx > 0 && idx - 1 != i && abs(arr[i] + arr[idx - 1]) < diff)
        {
            diff = abs(arr[i] + arr[idx - 1]);
            idx = idx - 1;
        }

        // 정답 후보 업데이트
        if (idx != i && last > diff)
        {
            last = diff;
            ans = arr[i] < arr[idx] ? make_pair(arr[i], arr[idx]) : make_pair(arr[idx], arr[i]);
        }
    }

    cout << ans.first << ' ' << ans.second;

    return 0;
}