#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    
    string temp;
    
    while(true)
    {
        if(m == 0) break;
        int a = m % n;
        m /= n;
        if(a < 10) temp.push_back('0' + a);
        else temp.push_back('A' + (a-10));
    }
    reverse(temp.begin(), temp.end());
    cout << temp;
    
    return 0;
}