#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    string str;
    for (int i = 1; i <= n; i++)
        str += to_string(i);

    cout << str.find(to_string(n)) + 1;

    return 0;
}