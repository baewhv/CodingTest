#include <iostream>
using namespace std;
//lcm gcd
int main()
{
    int n, m, lcm = 0, gdc = 0;
    cin >> n >> m;
    if (n > m) swap(n, m);

    if (m % n == 0) lcm = n;
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0 && m % i == 0) lcm = i;
        }
    }
    cout << lcm << '\n';

    int nTemp = n;
    int mTemp = m;
    while (true)
    {
        if (nTemp == mTemp)
        {
            gdc = nTemp;
            break;
        }
        if (nTemp < mTemp) nTemp += n;
        else if (nTemp > mTemp) mTemp += m;
    }
    cout << gdc;
    return 0;
}
