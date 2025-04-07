#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    string name;
    string state;
    set<string, greater<string>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> state;
        if (state == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    for (const auto& name : s)
    {
        cout << name << '\n';
    }

    return 0;
}