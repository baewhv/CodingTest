#include <iostream>

using namespace std;

int main()
{
    int a1, a2, c, n, func1;
    cin >> a1 >> a2 >> c >>n;
    func1 = a1 * n + a2;
    cout << ((func1 <= (c * n))&&(a1 <= c)) ? 1 : 0;
    
    return 0;
}