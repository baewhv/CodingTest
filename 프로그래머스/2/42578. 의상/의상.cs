using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) {
        int answer = 1;
        Dictionary<string,int> Dict = new Dictionary<string,int>();
        for(int i = 0; i < clothes.GetLength(0); i++)
        {
            if(Dict.ContainsKey(clothes[i,1]))
                Dict[clothes[i,1]]++;
            else
                Dict[clothes[i,1]] = 1;
        }
        foreach(KeyValuePair<string,int> pair in Dict)
        {
            answer *= pair.Value+1;
        }

        
        return answer-1;
    }

}