using System;

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
        int temp = 0;
        for(int i = 1; i*i <= n; i++)
        {
            if(i*i == n) temp++;
            else if(n%i == 0) temp +=2;
        }
        return temp;
    }
}