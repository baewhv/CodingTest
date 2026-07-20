#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    unordered_map<char, int> V;
    V['A'] = 1;
    V['E'] = 2;
    V['I'] = 3;
    V['O'] = 4;
    V['U'] = 5;
    while(word.length() != 5)
    {
        word += " ";
    }
    for(int i = 0; i < word.length();i++)
    {
        if(word[i] == ' ') break;
        int temp = 0;
        for(int j = 1; j < word.size()-i; j++)
        {
            temp += pow(5, j);
        }
        answer += V[word[i]] + temp * (V[word[i]]-1);
    }
    return answer;
}