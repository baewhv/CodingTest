#include<iostream>
#include<unordered_map>

using namespace std;

int func(int n, unordered_map<int, int>& m)
{
    if(n == 0) return 1;
    else if(n < 0) return 0;
    if(m.find(n) != m.end()) return m[n];
    m[n] = 0;
    m[n] += func(n-3, m) +func(n-2, m) + func(n-1, m);
    return m[n];
}

int main()
{
    int n, temp;
    cin >> n;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        cout << func(temp, m) << '\n';
    }
    
    
    return 0;
}