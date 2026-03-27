#include <iostream>

using namespace std;

int main()
{
    int x, y;
    int ans = 1;
    cin >> x >> y;
    
    if(x*y < 0) ans +=1;
    if(y < 0) ans +=2;
    cout << ans << endl;
    return 0;
}