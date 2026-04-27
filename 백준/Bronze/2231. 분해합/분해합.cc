#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp = to_string(n).size();
    
    int startNum = n - ((temp-1) * 9);
    if(startNum >0 && to_string(startNum).size() != temp)
        temp--;
    for(int i = n-(temp*9); i< n; i++ )
    {
        temp = i;
        int temp2 = i;
        while(true)
        {
            if(temp2 == 0) break;
            temp += temp2%10;
            temp2 /= 10;
        }
        if(temp == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    
    return 0;
}