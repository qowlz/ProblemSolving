#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define MAX_CLASS 5

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(MAX_CLASS, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_CLASS; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = -1;
    int maxTotal = -1;
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;

            // 같은 반이었던적이 있는지 체크
            for (int k = 0; k < MAX_CLASS; k++)
            {
                // 학년 체크를 안한다.
                if (arr[i][k] == arr[j][k])
                {
                    total++;
                    break;
                }
            }
        }

        if (maxTotal < total)
        {
            maxTotal = total;
            ans = i + 1;
        }
    }

    cout << ans;

    return 0;
}