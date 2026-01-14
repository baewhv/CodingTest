using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int a, int b, int c) {
        int answer = a+b+c;
        
        SortedSet<int> temp = new SortedSet<int>();
        temp.Add(a);
        temp.Add(b);
        temp.Add(c);
        switch(temp.Count)
        {
            case 1:
                answer *= Mul(a, 2) * 3 * Mul(a, 3) * 3;
                break;
            case 2:
                answer *= Mul(a,2) + Mul(b,2) + Mul(c,2);
                break;
        }
        return answer;
    }
    
    public  int Mul(int num, int mul)
    {
        int temp  = 1;
        for(int i = 0; i < mul; i++)
        {
            temp *= num;
        }
        return temp;
    }
}