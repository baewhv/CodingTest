using System;
using System.Collections.Generic;

class program
{
    static void Main(string[] args)
    {
        int comNum = int.Parse(Console.ReadLine());
        int linkNum = int.Parse(Console.ReadLine());
        bool[,] Network = new bool[comNum, comNum];
        for(int i = 0; i < linkNum; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]) - 1; //인덱스 기준을 배열로
            int b = int.Parse(input[1]) - 1;
            Network[a, b] = true;
            Network[b, a] = true;
        }
        Console.WriteLine(FindVirus(Network));
    }
    
    static int FindVirus(bool[,] Network)
    {
        Stack<int> q = new Stack<int>();
        bool[] visit = new bool[Network.GetLength(0)];
        int here = 0;
        q.Push(0);
        int viruses = 0;
        visit[0] = true;
        while(true)
        {
            if(q.Count == 0) break;
            here = q.Pop();
            for(int there = 0; there < Network.GetLength(0); there++)
            {
                if(here == there) continue;
                if (visit[there]) continue;
                if(Network[here,there] == false) continue;
                visit[there] = true;
                q.Push(there);
                viruses++;
            }
        }
        return viruses;
    }
}