using System;
using System.Collections.Generic;

class Solution
{
    int Height;
    int Width;
    
    public int solution(int[,] maps)
    {
        Height = maps.GetLength(0);
        Width = maps.GetLength(1);
        return BFS(maps);
    }

    int BFS(int[,] maps)
    {
        Queue<Pos> q = new Queue<Pos>();
        Pos[] dir = new Pos[4];
        dir[0] = new Pos(1, 0, 1);
        dir[1] = new Pos(0, 1, 1);
        dir[2] = new Pos(-1, 0, 1);
        dir[3] = new Pos(0, -1, 1);
        bool[,] Visited = new bool[Height, Width];

        Pos here = new Pos(0, 0, 1);
        Visited[here.y, here.x] = true;
        q.Enqueue(here);

        while (true)
        {
            if (q.Count == 0) break;
            here = q.Dequeue();
            if (here.x == Width-1 && here.y == Height-1)
            {
                return here.weight;
            }

            for (int i = 0; i < 4; i++)
            {
                Pos there = here + dir[i];
                if (!CanMove(there, maps) || Visited[there.y, there.x]) continue;
                q.Enqueue(there);
                Visited[there.y, there.x] = true;
                
            }
        }


        return -1;
    }
    bool CanMove(Pos pos, int[,] map)
    {
        if (pos.x < 0 || pos.y < 0 || pos.x >= Width || pos.y >= Height) return false;
        if (map[pos.y, pos.x] == 0) return false;
        return true;
    }

    class Pos
    {
        public int x;
        public int y;
        public int weight;

        public Pos(int _x, int _y)
        {
            x = _x;
            y = _y;
            weight = 0;
        }

        public Pos(int _x, int _y, int _weight)
        {
            x = _x;
            y = _y;
            weight = _weight;
        }

        public static Pos operator +(Pos left, Pos right)
        {
            return new Pos(left.x + right.x, left.y + right.y, left.weight + right.weight);
        }
    }
}