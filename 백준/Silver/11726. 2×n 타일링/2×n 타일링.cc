#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

long long pac(int r, int l, unordered_map<string, int>& map)
{
    if (r < l) swap(r, l);
    string temp = to_string(r) + "_" + to_string(l);
    if (map.find(temp) != map.end()) return map[temp];
    if (r == 0 || l == 0) return 1;
    if (r == 1 || l == 1) return r + l;
    map[temp] = (pac(r - 1, l, map) + pac(r, l - 1, map))%10007;
    return map[temp];
}

int main()
{
    int n, two, one;
    unordered_map<string, int> map;
    long long cnt = 0;
    cin >> n;
    two = n / 2;
    one = n % 2;
    for (int i = two; i >= 0; i--)
    {
        cnt += pac(i, one, map);
        one += 2;
    }
    cout << cnt % 10007;

    return 0;
}