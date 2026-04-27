#include <iostream>
#include <unordered_map>
using namespace std;

int sq(int n)
{
    int temp = 1;
    while (true)
    {
        if ((temp+1) * (temp+1) > n) return temp;
        temp++;
    }
}


int func(int n, unordered_map<int, int>& m)
{
    if (n == 1) return 1;
    if (m.find(n) != m.end()) return m[n];
    int temp = sq(n);
    if (temp * temp == n)
    {
        m[n] = 1;
        return 1;
    }
    m[n] = n;
    for (int i = temp; i >= 1; i--)
    {
        m[n] = min(m[n], func(n - i*i, m) + 1);
    }
    return m[n];
}

int main()
{
    int n, temp = 0, sq = 1;
    cin >> n;

    unordered_map<int, int> m;

    cout << func(n, m);

    return 0;
}