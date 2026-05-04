using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.Length];
        Stack<int> s = new Stack<int>();
        for(int i = 0; i < prices.Length; i++)
        {
            while(true)
            {
                if(s.Count == 0) break;
                if(prices[s.Peek()] <= prices[i]) break;
                answer[s.Peek()] = i - s.Peek();
                s.Pop();
            }
            s.Push(i);
        }
        while(true)
        {
            if(s.Count == 0) break;
            answer[s.Peek()] = prices.Length - s.Peek() - 1;
            s.Pop();
        }
        
        return answer;
    }
}