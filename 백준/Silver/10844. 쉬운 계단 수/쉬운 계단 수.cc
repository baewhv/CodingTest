#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int func(int n, int depth, vector<unordered_map<int, long long>>& m)
{
    if (depth == 1) return 1;
    if (m[n].find(depth) != m[n].end()) return m[n][depth];

    m[n][depth] = ((n - 1 < 0 ? 0 : func(n - 1, depth - 1, m)) + (n+1 > 9 ? 0 : func(n+1, depth-1,m))) % 1000000000;

    return m[n][depth];
}

int main()
{
    int n, temp = 0;
    cin >> n;
    vector<unordered_map<int, long long>> m(10, unordered_map<int, long long>());

    for (int i = 1; i < 10; i++)
    {
        temp += func(i, n, m);
        temp %= 1000000000;
    }
    cout << temp;
    return 0;
}