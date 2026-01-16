using System;
using System.Collections.Generic;
using System.Text;

public class Solution {
    string answer = null;
    string num;
    public string solution(string number, int k) {
        num = number;
        Function(new StringBuilder(), 0, number.Length-k);
        return answer;
    }
    public void Function(StringBuilder value, int point, int max)
    {
        if(value.Length + (num.Length - point) < max) return;
        if(value.Length == max) 
        {
            answer = value.ToString();
            return;
        }
        for(int i = 9; i >= 0; i--)
        {
            for(int j = point; j < num.Length && value.Length + (num.Length - j) >= max; j++)
            {
                if('0' + i == num[j])
                {
                    Function(value.Append(num[j]), j+1, max);
                    if(answer != null) return;
                }
            }
        }
    }
}