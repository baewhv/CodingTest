#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int func(int n, int stack, vector<unordered_map<int, int>>& map)
{
    if (stack == 0) return 1;
    if (map[stack].find(n) != map[stack].end()) return map[stack][n];
    map[stack][n] = 0;
    for (int i = 0; i <= n; i++)
    {
        map[stack][n] = (map[stack][n] + func(n - i, stack - 1, map)) % 1000000000;
    }
    return map[stack][n] % 1000000000;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<unordered_map<int, int>> map(k, unordered_map<int, int>());
    cout << func(n, k-1, map) % 1000000000;

    return 0;
}