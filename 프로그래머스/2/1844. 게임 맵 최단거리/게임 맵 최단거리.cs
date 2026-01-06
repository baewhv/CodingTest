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
    
//     class PriorityQueue
//     {
//         Pos[] arr;
//         public int Count { get; private set; }
//         int Capacity;
        
//         public PriorityQueue()
//         {
//             Capacity = 16;
//             arr = new Pos[Capacity];
//             Count = 0;
//         }
//         public void Enqueue(Pos data)
//         {
//             if(Count+1 > Capacity)
//                 Resize();
//             if (Count == 0)
//             {
//                 arr[1] = data;
//                 Count++;
//             }
//             int pivot = Count+1;   
//             while(true)
//             {
//                 int nextPivot = pivot / 2;
//                 if(nextPivot < 1) break;
//                 if(arr[nextPivot].weight > data.weight)
//                 {
//                     arr[pivot] = arr[nextPivot];
//                     pivot = nextPivot;
//                 }
//                 else
//                 {
//                     arr[pivot] = data;
//                     break;
//                 }
//             }
//             Count++;
//         }
//         public Pos Dequeue()
//         {
//             Pos temp = arr[1];
//             int pivot = 1;
//             while(true)
//             {
//                 if(pivot * 2 <= Count)
//                 {
//                     if(pivot * 2 + 1 <= Count)
//                     {
//                         if(arr[pivot*2].weight < arr[pivot*2+1].weight)
//                         {
//                             arr[pivot] = arr[pivot*2];
//                             pivot *= 2;
//                         }
//                         else
//                         {
//                             arr[pivot] = arr[pivot*2+1];
//                             pivot = pivot * 2 + 1;
//                         }
//                     }
//                     arr[pivot] = arr[pivot*2];
//                     pivot *= 2;
//                 }
//                 else
//                 {
//                     for(int i = pivot; i < Count; i++)
//                     {
//                         arr[i] = arr[i+1];
//                     }
//                     break;
//                 }
//             }
//             Count--;
//             return temp;
//         }
//         void Resize()
//         {
//             Pos[] temp = new Pos[Capacity*2];
//             for(int i = 0; i < arr.Length; i++)
//             {
//                 temp[i] = arr[i];
//             }
//             arr = temp;
//         }

//     }
}