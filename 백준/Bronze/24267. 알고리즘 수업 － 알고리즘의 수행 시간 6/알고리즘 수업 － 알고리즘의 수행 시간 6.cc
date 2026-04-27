#include <iostream>

using namespace std;



int main()
{
    long long n, temp = 0;
    cin >> n;
    for(int i = 1; i <= n-2; i++)
    {
        temp += i * ((n-2) -(i-1));
    }
    cout << temp << '\n' << 3;
    
    return 0;
}