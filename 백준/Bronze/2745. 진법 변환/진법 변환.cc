#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string temp;
    cin >> temp;
    int n;
    cin >> n;
    
    long long answer = 0;
    
    for(int i = 0; i < temp.length(); i++)
    {
        int num;
        if(temp[i]>='0' && temp[i]<='9') num = temp[i] - '0';
        else num = temp[i] - 'A' + 10;
        
        answer += pow(n, (temp.length()-1) - i) * num;
    }
    cout << answer;
        
    
    return 0;
}