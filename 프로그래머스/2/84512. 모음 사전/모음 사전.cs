using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string word) {
        int answer = 0;
        Dictionary<char, int> dic = new();
        dic['A'] = 1;
        dic['E'] = 2;
        dic['I'] = 3;
        dic['O'] = 4;
        dic['U'] = 5;
        while(word.Length != 5)
        {
            word = $"{word} ";
        }
        for(int i = 0; i < word.Length; i++)
        {
            if(word[i] == ' ') break;
            int temp = 0;
            for(int j = 1; j < dic.Count-i; j++)
            {
                temp += (int)Math.Pow(5, j);
            }
            answer += dic[word[i]] + temp * (dic[word[i]]-1);
        }
        return answer;
    }
}
