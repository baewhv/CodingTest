using System.Text;

public class Solution {
    public string solution(string s, int n) {
        StringBuilder answer = new StringBuilder(s);
        for(int i = 0; i < answer.Length; i++)
        {
            if(answer[i] == ' ') continue;
            int temp;
            if(answer[i] <= 'Z') temp = 'A';
            else temp = 'a';
            answer[i] -= (char)temp;
            answer[i] = (char)((answer[i] + 26 + n) % 26);
            answer[i] += (char)temp;
            
        }
        return answer.ToString();
    }
}