#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double gradeToNum(string str)
{
    if (str == "A+") return 4.5;
    else if (str == "A0") return 4.0;
    else if (str == "B+") return 3.5;
    else if (str == "B0") return 3.0;
    else if (str == "C+") return 2.5;
    else if (str == "C0") return 2.0;
    else if (str == "D+") return 1.5;
    else if (str == "D0") return 1.0;

    return 0.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double total = 0.0;
    double sum = 0.0;
    for (int i = 0; i < 20; i++)
    {
        string name, grade;
        double score;
        cin >> name >> score >> grade;

        if (grade == "P") continue;

        sum += score * gradeToNum(grade);
        total += score;
    }

    cout << setprecision(7) << (sum / total);

    return 0;
}