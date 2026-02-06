using System.Text;
public class Solution {
    public string solution(string phone_number) {
        StringBuilder answer = new StringBuilder(phone_number);
        for(int i = 0; i < phone_number.Length-4; i++)
        {
            answer[i] = '*';
        }

        return answer.ToString();
    }
}