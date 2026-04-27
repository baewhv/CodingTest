#include <iostream>
using namespace std;

int main()
{
    int n, width = 2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        width = width + (width - 1);
    }
    cout << width * width;

    return 0;
}