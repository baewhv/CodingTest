#include <iostream>
#include <string>

using namespace std;


bool func(int n)
{
    int cnt = 0;
    while (true)
    {
        if (n % 10 == 6)
        {
            cnt++;
            if (cnt == 3) return true;
        }
        else cnt = 0;
        if (n / 10 == 0) break;
        n /= 10;
    }
    return false;
}

int main()
{
    int n, cnt = 0, num = 666;
    cin >> n;

    while (true)
    {
        if (func(num))
        {
            cnt++;
            if (cnt == n)
            {
                cout << num;
                return 0;
            }
        }
        num++;
    }
    return 0;
}