using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] s1, string[] s2) {
        int answer = 0;
        HashSet<string> HS = new HashSet<string>(s1);
        for(int i = 0; i < s2.Length; i++)
        {
            if(HS.Contains(s2[i]))
                answer++;
        }
        
        return answer;
    }
}