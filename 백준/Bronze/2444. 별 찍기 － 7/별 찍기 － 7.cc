#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < n - 1 - (i < (n - 1) ? i : 2 * (n - 1) - i); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < ((i<(n-1) ? i : 2 * (n - 1) - i) * 2) + 1; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}