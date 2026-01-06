using System;
using System.Collections.Generic;

public class Solution {
    Dictionary<char, Pos> Directions = new Dictionary<char, Pos>();
    public int solution(string dirs) {
        Directions['U'] = new Pos(0, 1);
        Directions['D'] = new Pos(0, -1);
        Directions['R'] = new Pos(1, 0);
        Directions['L'] = new Pos(-1, 0);
        bool[,] VerticalVisited = new bool[11,11];
        bool[,] HorizontalVisited = new bool[11,11];
        Pos here = new Pos(0,0);
        int CheckRoad = 0;
        for(int i = 0; i < dirs.Length; i++)
        {
            Pos there = here + Directions[dirs[i]];
            if(there.x < -5 || there.y < -5 || there.x > 5 || there.y > 5) continue;
            if(dirs[i] == 'U')
            {
                if(!VerticalVisited[here.y+5, here.x+5])
                {
                    VerticalVisited[here.y+5, here.x+5] = true;
                    CheckRoad++;
                }
            }
            else if(dirs[i] == 'D')
            {
                if(!VerticalVisited[there.y+5, there.x+5])
                {
                    VerticalVisited[there.y+5, there.x+5] = true;
                    CheckRoad++;
                }
            }
            else if (dirs[i] == 'R')
            {
                if(!HorizontalVisited[here.y+5, here.x+5])
                {
                    HorizontalVisited[here.y+5, here.x+5] = true;
                    CheckRoad++;
                }
            }
            else
            {
                if(!HorizontalVisited[there.y+5, there.x+5])
                {
                    HorizontalVisited[there.y+5, there.x+5] = true;
                    CheckRoad++;
                }
            }
            here = there;
        }
        
        return CheckRoad;
    }
    
    class Pos
    {
        public int x;
        public int y;
        public Pos(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
        
        public static Pos operator +(Pos left, Pos right)
        {
            return new Pos(left.x + right.x, left.y + right.y);
        }

        
    }
}