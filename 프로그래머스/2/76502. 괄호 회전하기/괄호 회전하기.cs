using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string s) {
        int answer = 0;
        Queue<char> q = new Queue<char>(s);
        for(int i = 0; i < s.Length; i++)
        {
            Queue<char> temp = new Queue<char>(q);
            answer += Check(temp);
            q.Enqueue(q.Dequeue());
        }
        return answer;
    }
    
    private int Check(Queue<char> q)
    {
        Stack<char> s = new Stack<char>();
        while(q.Count != 0)
        {
            if(s.Count == 0)
            {
                if(q.Peek() == '}' || q.Peek() == ')' ||q.Peek() == ']' ) return 0;
                s.Push(q.Dequeue());
            }
            else
            {
                if (q.Peek() == '[' || q.Peek() == '(' || q.Peek() == '{')
                {
                    s.Push(q.Dequeue());
                    continue;
                }

                switch (s.Peek())
                {
                    case '[' :
                        if (q.Peek() != ']') return 0;
                        break;
                    case '(' :
                        if (q.Peek() != ')') return 0;
                        break;
                    case '{' :
                        if (q.Peek() != '}') return 0;
                        break;
                }
                s.Pop();
                q.Dequeue();
            }
        }
        return s.Count == 0 ? 1 : 0;
    }
}