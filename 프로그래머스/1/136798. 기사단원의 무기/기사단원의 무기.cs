using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for(int i = 1; i <= number;i++)
        {         
            int div = GetDivisor(i);
            if(div > limit)
                answer += power;
            else
                answer += div;
        }
        return answer;
    }
    public int GetDivisor(int n)
    {
        HashSet<int> temp = new HashSet<int>();
        for(int i = 1; i*i <= n; i++)
        {
            
            if(n%i == 0)
            {
                temp.Add(i);
                temp.Add(n/i);
            }
        }
        return temp.Count;
    }
}