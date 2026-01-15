public class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2] {1, 1};
        if(n > m)
        {
            int temp = n;
            n = m;
            m = temp;
        }
        for(int i = 2; i <= n; i++)
        {
            if(m%i == 0 && n%i == 0)
                answer[0] = i;
        }
        int n2 = n;
        int m2 = m;
        while(n2 != m2)
        {
            if(n2 > m2) m2 += m;
            else if(n2 < m2) n2 += n;
        }
        answer[1] = n2;

        return answer;
    }
}