using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int[] ingredient)
    {
        int answer = 0;
        Stack<int> s = new();
        for (int i = 0; i < ingredient.Length; i++)
        {
            switch (ingredient[i])
            {
                case 1:
                    if (s.Count == 0 || s.Peek() != 3)
                    {
                        s.Push(1);
                    }
                    else if (s.Peek() == 3)
                    {
                        s.Pop();
                        s.Pop();
                        s.Pop();
                        answer++;
                    }

                    break;
                case 2:
                    if (s.Count == 0) continue;
                    if (s.Peek() == 1)
                    {
                        s.Push(2);
                    }
                    else
                    {
                        s.Clear();
                    }

                    break;
                case 3:
                    if (s.Count == 0) continue;
                    if (s.Peek() == 2)
                    {
                        s.Push(3);
                    }
                    else
                    {
                        s.Clear();
                    }

                    break;
            }
        }

        return answer;
    }
}