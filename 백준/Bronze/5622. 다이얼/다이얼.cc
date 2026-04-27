#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> dial = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s)
    {
        ans += dial[c - 'A'];
        ans++;
    }
    cout << ans;

    return 0;
}