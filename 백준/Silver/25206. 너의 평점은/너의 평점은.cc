#include <iostream>
#include <string>

using namespace std;

int main()
{
    float avg = 0.0f;
    float total = 0.0f;
    for (int i = 0; i < 20; i++)
    {
        string name, rank;
        float score, subScore = 0.0f;
        cin >> name >> score >> rank;
        
        switch (rank[0])
        {
        case 'A':
            subScore += 1.0f;
        case 'B':
            subScore += 1.0f;
        case 'C':
            subScore += 1.0f;
        case 'D':
            subScore += 1.0f + (rank[1] == '+' ? 0.5f : 0.0f);
        case 'F':
            total += score;
            break;
        }
        avg += score * subScore;
    }
    cout << avg / total;


    return 0;
}