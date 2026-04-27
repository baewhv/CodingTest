#include <iostream>

using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        cin >> temp;
        if (temp == 1)
        {
            n--;
        }
        for (int j = 2; j * j <= temp; j++)
        {
            if (temp % j == 0)
            {
                n--;
                break;
            }
        }
    }
    cout << n << endl;

    return 0;
}