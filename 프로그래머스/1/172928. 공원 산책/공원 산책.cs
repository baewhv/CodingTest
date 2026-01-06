using System;
using System.Collections.Generic;

public class Solution {
    string[] map;
    Dictionary<char, Pos> Directions = new Dictionary<char,Pos>();
    public int[] solution(string[] park, string[] routes) {
        Pos mecaDog = new Pos();
        Directions['E'] = new Pos(1,0);
        Directions['W'] = new Pos(-1,0);
        Directions['S'] = new Pos(0,1);
        Directions['N'] = new Pos(0,-1);
        map = park;
        for(int i = 0; i < park.Length; i++)
        {
            mecaDog.x = park[i].IndexOf('S');
            mecaDog.y = i;
            if(mecaDog.x != -1)
                break;
        }
        for(int i = 0; i < routes.Length; i++)
        {
            TryMove(ref mecaDog, routes[i][0], routes[i][2]-'0');
        }
        
        return mecaDog.ToArray();
    }
    private void TryMove(ref Pos dog, char dir, int moves)
    {
        Pos temp = dog + (Directions[dir] * moves);
        if(temp.x < 0 || temp.y < 0 || temp.x >= map[0].Length || temp.y >= map.Length) return;
        if(map[temp.y][temp.x] == 'X') return;
        Pos dogTemp = dog;
        while(temp != dogTemp)
        {
            dogTemp += Directions[dir];
            if(map[dogTemp.y][dogTemp.x] == 'X') return;
        }
        dog = dogTemp;
    }
    
    struct Pos
    {
        public int x;
        public int y;
        public Pos(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
        public int[] ToArray()
        {
            return new int[2] {y, x};
        }
        public static Pos operator*(Pos left, int value)
        {
            return new Pos(left.x * value, left.y * value);
        }
        public static Pos operator+(Pos left, Pos right)
        {
            return new Pos(left.x + right.x, left.y + right.y);
        }
        public static bool operator==(Pos left, Pos right)
        {
            return left.x == right.x && left.y == right.y;
        }
        
        public static bool operator!=(Pos left, Pos right)
        {
            return left.x != right.x || left.y != right.y;
        }
    }
}