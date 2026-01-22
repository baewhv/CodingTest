using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n) {
        int answer = n/2 + n%2;
        bool[] check = new bool[n+1];
        for(int i = 3; i <= n; i+=2)
        {
            if(check[i] == true) continue;
            long temp = 3 * (long)i;
            while(temp <= n)
            {
                if(!check[temp])
                {
                    answer--;
                    check[temp] = true;
                }
                temp += i * 2;
            }
        }
        return answer;
    }
}