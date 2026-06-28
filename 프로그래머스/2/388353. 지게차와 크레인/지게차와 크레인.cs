using System;
using System.Collections.Generic;
using System.Diagnostics;

public class Solution
{
    Queue<Box> q = new();
    int[,] type;
    string[] _storage;
    int _width;
    int _height;

    public int solution(string[] storage, string[] requests)
    {
        _height = storage.Length;
        _width = storage[0].Length;
        int answer = _width * _height;
        type = new int [_height, _width];
        _storage = storage;

        for (int i = 0; i < requests.Length; i++)
        {
            CheckBox(requests[i][0], requests[i].Length > 1);
            answer -= q.Count;
            RemoveBox();
        }

        return answer;
    }

    public void CheckBox(char Con, bool UseCrane)
    {
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                if (_storage[y][x] != Con) continue;
                if (type[y, x] != 0) continue;
                Box here = new Box(x, y);
                if (UseCrane)
                {
                    here.type = 1;
                    q.Enqueue(here);
                }
                else if (CanFork(here))
                {
                    here.type = -1;
                    q.Enqueue(here);
                }
            }
        }
    }
    
    public bool CanFork(Box here)
    {
        Stack<Box> boxes = new Stack<Box>();
        bool[,] visit = new bool[_height, _width];
        
        boxes.Push(here);
        visit[here.y, here.x] = true;
        while (true)
        {
            if (boxes.Count == 0) break;
            here = boxes.Pop();
            for (int i = 0; i < Box.Direction.Length; i++)
            {
                Box there = here + Box.Direction[i];
                if (CheckBorder(there)) //테두리라면 빼낼 수 있음.
                {
                    //ChangeEmptySlot(boxes);
                    return true;
                }
                if (visit[there.y, there.x]) continue; //이미 지나간곳이면 패스 
                switch(type[there.y, there.x])
                {
                    case -1: //바깥과 연결된 비어있는 컨테이너
                        //ChangeEmptySlot(boxes);
                        return true;
                    case 0:  //컨테이너
                        visit[there.y, there.x] = true;
                        break;
                    case 1:  //크레인으로 제거한 컨테이너
                        visit[there.y, there.x] = true;
                        boxes.Push(there);
                        break;
                }
            }
        }
        return false;
    }

    private void ChangeEmptySlot(Stack<Box> Route)
    {
        while (Route.Count != 0)
        {
            type[Route.Peek().y, Route.Peek().x] = -1;
            Route.Pop();
        }
    }

    private bool CheckBorder(Box box)
    {
        if (box.x  < 0 ||
            box.y  < 0 ||
            box.x  >= _width ||
            box.y  >= _height) return true;
        return false;
    }

    private void RemoveBox()
    {
        while (q.Count != 0)
        {
            type[q.Peek().y, q.Peek().x] = q.Peek().type;
            q.Dequeue();
        }
    }

    public struct Box
    {
        public static Box[] Direction = [new Box(1, 0), new Box(-1, 0), new Box(0, 1), new Box(0, -1)];
        
        public int x;
        public int y;
        public int type;
        
        
        public Box (int _x, int _y)
        {
            x = _x;
            y = _y;
        }
        
        public static Box operator+(Box left, Box right)
        {
            return new Box(left.x + right.x, left.y + right.y);
        }
    }
}