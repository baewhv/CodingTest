#include <iostream>
using namespace std;

void func(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return;
    }
    cout << n << '\n';
}


int main()
{
    int n, m;
    cin >> n >> m;
    if (n <= 2)
    {
        cout << 2 << '\n';
        n = 3;
    }

    n = n % 2 == 0 ? n + 1 : n;
    for (int i = n; i <= m; i += 2)
    {
        func(i);
    }

    return 0;
}