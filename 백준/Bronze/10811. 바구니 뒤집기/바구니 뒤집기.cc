#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, l, r;
    cin >> n >> m;
    vector<int> basket(n + 1);
    for (int i = 1; i <= n; i++)
    {
        basket[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        reverse(basket.begin() + l, basket.begin() + r+1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << basket[i]<< ' ';
    }
    return 0;
}