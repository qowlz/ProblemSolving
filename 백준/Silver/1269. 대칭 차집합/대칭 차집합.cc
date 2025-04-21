#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n1, n2;
    cin >> n1 >> n2;

    unordered_set<int> a;
    for (int i = 0; i < n1; i++)
    {
        int num;
        cin >> num;
        a.insert(num);
    }

    unordered_set<int> b;
    for (int i = 0; i < n2; i++)
    {
        int num;
        cin >> num;
        b.insert(num);
    }

    unordered_set<int> ans;
    for (auto x : a)
    {
        if (b.find(x) != b.end()) continue;
        ans.insert(x);
    }

    for (auto x : b)
    {
        if (a.find(x) != a.end()) continue;
        ans.insert(x);
    }

    cout << ans.size();

    return 0;
}