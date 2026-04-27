#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int func(int n, unordered_map<int, int>& m)
{
    if(m.find(n) != m.end()) return m[n];
    m[n] = (func(n-1, m) + func(n-2,m) * 2) %10007;
    return m[n];
}


int main()
{
    int n = 0;
    unordered_map<int, int> m;
    cin >> n;
    m[1] = 1;
    m[2] = 3;
    cout << func(n, m) % 10007;
    return 0;
}