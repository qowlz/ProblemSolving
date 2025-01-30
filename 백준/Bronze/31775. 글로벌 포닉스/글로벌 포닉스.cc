#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    int sl = 0, sk = 0, sp = 0;
    vector<string> strs {a, b, c};
    for (auto& str : strs)
    {
        if (str.length() <= 0) continue;

        if (str[0] == 'l') sl++;
        if (str[0] == 'k') sk++;
        if (str[0] == 'p') sp++;
    }

    if (sl && sk && sp)
        cout << "GLOBAL";
    else
        cout << "PONIX";

    return 0;
}