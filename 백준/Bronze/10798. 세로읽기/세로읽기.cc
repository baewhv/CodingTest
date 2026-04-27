#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> words(5);
    int maxNum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> words[i];
        maxNum = max(maxNum, static_cast<int>(words[i].length()));
    }

    for (int i = 0; i < maxNum; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (words[j].length() > i)
                cout << words[j][i];
        }
    }




    return 0;
}