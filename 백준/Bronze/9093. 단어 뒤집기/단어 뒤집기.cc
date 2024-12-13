#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    while(t--)
    {
        string s;
        getline(cin, s);

        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ') st.push(s[i]);

            if (s[i] == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
        }

        if (!st.empty())
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }

        cout << '\n';
    }

    return 0;
}