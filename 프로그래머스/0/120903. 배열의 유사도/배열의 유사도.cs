using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] s1, string[] s2) {
        int answer = 0;
        Array.Sort(s1);
        Array.Sort(s2);
        int sNum1 = 0;
        int sNum2 = 0;
        Console.WriteLine();
        while(sNum1 < s1.Length && sNum2 < s2.Length)
        {
            switch(String.Compare(s1[sNum1], s2[sNum2]))
            {
                case -1:
                    sNum1++;
                    break;
                case 0:
                    answer++;
                    sNum1++;
                    sNum2++;
                    break;
                case 1:
                    sNum2++;
                    break;
            }
        }
        return answer;
    }
}