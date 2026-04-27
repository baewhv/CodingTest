#include <iostream>

using namespace std;

int main()
{
    int n, line = 1;
    cin >> n;

    while (true)
    {
        if (n - line <= 0) break;
        n -= line;
        line++;
    }

    cout << (line % 2 == 0 ? n : line - (n-1)) << "/" << (line % 2 == 0 ? line - (n-1) : n);
    return 0;
}