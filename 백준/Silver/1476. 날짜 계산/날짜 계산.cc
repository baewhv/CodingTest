#include <iostream>
using namespace std;

int main()
{
    int e, s, m, answer = 0;
    cin >> e >> s >> m;

    while (e != 1 || s != 1 || m != 1)
    {
        int maxN = max(e, max(s, m));
        e = (e + 30 - maxN) % 15 + 1;
        s = (s + 28 - maxN) % 28 + 1;
        m = (m + 38 - maxN) % 19 + 1;
        answer += maxN - 1;
    }
    cout << answer+1;
}