#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, sum;
    cin >> n>>sum;
    vector<int> cards;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }
    int temp = 0;
    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                int sum2 = cards[i] + cards[j] + cards[k];
                if(sum2 > sum) continue;
                if(sum2 == sum)
                {
                    cout << sum2 << endl;
                    return 0;
                }
                temp = max(temp, sum2);
            }
        }
    }
    cout << temp << endl;

        
    
    
    return 0;
}