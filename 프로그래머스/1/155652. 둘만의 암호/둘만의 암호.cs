using System;
using System.Text;
using System.Collections.Generic;

public class Solution {
    public string solution(string s, string skip, int index) {
        StringBuilder answer = new StringBuilder(s);
        HashSet<char> hs = new HashSet<char>(skip);
        for(int i = 0; i < answer.Length; i++)
        {
            for(int j = 0; j < index; j = j)
            {
                if(answer[i] == 'z') answer[i] = 'a';
                else answer[i]++;
                if(!hs.Contains(answer[i]))
                    j++;
            }
        }
        
        return answer.ToString();
    }
}