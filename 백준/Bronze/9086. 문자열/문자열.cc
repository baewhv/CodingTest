#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        cout << temp[0] << temp[temp.length()-1]<< '\n';
    }
    
    return 0;
}