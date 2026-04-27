#include <iostream>
using namespace std;

int main()
{
    int n = 0, x = 0, y = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int temp;
            cin >> temp;
            if (n < temp)
            {
                n = temp;
                x = j;
                y = i;
            }
        }
    }
    cout << n << '\n' << y+1 << ' ' << x+1;

    return 0;
}