using System;
using System.Text;

public class Solution {
    private int[] answer;
    public int[] solution(string s) {
        answer = new int[2];
        StringBuilder sb = new StringBuilder(s);
        while(sb.Length != 1 || sb[0] != '1')
        {
            CheckZero(sb);
            sb = ParseBinary(sb.Length);
        }
        return answer;
    }
    private void CheckZero(StringBuilder sb)
    {
        for(int i = 0; i < sb.Length; i=i)
        {
            if (sb[i] == '0')
            {
                answer[1]++;
                sb.Remove(i, 1);
            }
            else i++;
        }
        sb.Replace('0', '\0');
    }
    private StringBuilder ParseBinary(int num)
    {
        StringBuilder temp = new StringBuilder();
        while(num > 0)
        {
            temp.Append(num % 2 == 0 ? '0' : '1');
            num /= 2;
        }
        answer[0]++;
        return temp;
    }
}