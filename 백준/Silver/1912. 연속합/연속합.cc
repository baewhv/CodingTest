#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, temp, maxN = -1000, sumN = -1000;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (i == 0) sumN = temp;
        else
        {
            if (temp < 0)
            {
                if (sumN + temp > 0) sumN += temp;
                else sumN = temp;
            }
            else
            {
                sumN += temp;
            }
            
        }
        maxN = max(maxN, sumN);
        if(sumN < 0) sumN = 0;
    }

    cout << maxN;

}