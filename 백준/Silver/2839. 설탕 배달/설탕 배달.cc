#include <iostream>

using namespace std;

int main()
{
    int n, five = 0;
    cin >> n;
    five = n / 5;
    n %= 5;
    while(true)
    {
        if (five < 0) break;
        if (n % 3 == 0)
        {
            cout << five + n / 3;
            return 0;
        }
        five--;
        n += 5;
    }
    cout << -1;
    return 0;
}