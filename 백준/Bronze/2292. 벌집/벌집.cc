#include <iostream>
using namespace std;
int main()
{
    int n, temp = 0;
    cin >> n;
    while (true)
    {
        n -= temp == 0 ? 1 : temp * 6;
        if (n <= 0)
        {
            cout << temp + 1;
            break;
        }
        
        temp++;
    }
    return 0;
}