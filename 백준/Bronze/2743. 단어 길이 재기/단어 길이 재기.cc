#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string temp;
    cin >> temp;
    
    for(auto it : temp)
    {
        n++;
    }
    cout << n;
        
    
    return 0;
}