using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.Length];
        Stack<int> s = new Stack<int>();
        s.Push(0);
        for(int i = 1; i < numbers.Length; i++)
        {
            while(true)
            {
                if(s.Count == 0) break;
                if(numbers[s.Peek()] >= numbers[i]) break;
                answer[s.Pop()] = numbers[i];
            }
            s.Push(i);
        }

        while (s.Count != 0)
        {
            answer[s.Pop()] = -1;
        }
        return answer;
    }
}