#include <iostream>

using namespace std;

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.eof()) break;
        int temp = 1;
        int x = 1;
        while (true)
        {
            if (temp % n == 0)
            {
                cout << x << "\n";
                break;
            }
            temp = (temp * 10 + 1) % n;
            x++;
        }
    }


    return 0;
}