#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x;
    cin >> x;

    int add = 1;
    int cnt = 1, row = 1, col = 1;
    while (cnt + add <= x)
    {
        if (add % 2)
            row++;
        else
            col++;

        swap(row, col);
        cnt += add;
        add++;
    }

    int sub = x - cnt;
    if (row == 1)
    {
        row += sub;
        col -= sub;
    }
    else
    {
        row -= sub;
        col += sub;
    }

    cout << row << '/' << col;

    return 0;
}