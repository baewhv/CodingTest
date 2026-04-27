#include <iostream>
using namespace std;

int main()
{
    int n, maxNum = 0, temp;
    
    for(int i = 0; i < 9; i++)
    {
        cin >> temp;
        if(maxNum < temp)
        {
            maxNum = temp;
            n = i+1;
        }
    }
    cout << maxNum << '\n' << n;
    return 0;
}