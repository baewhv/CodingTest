#include <iostream>

using namespace std;

int main()
{
    int a, b, v;
    cin >> a >> b >> v;
    v -= a;
    
    cout << v / (a - b) + (v % (a - b) > 0 ? 1 : 0) + 1;

    return 0;
}