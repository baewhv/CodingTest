using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int[,] points, int[,] routes)
    {
        int answer = 0;
        List<Bot> bots = new();
        for (int i = 0; i < routes.GetLength(0); i++)
        {
            Bot bot = new(points[routes[i, 0] - 1, 0], points[routes[i, 0] - 1, 1]);
            bot.id = i;
            bots.Add(bot);
        }

        while (bots.Count != 0)
        {
            Dictionary<(int, int), int> collision = new();
            for (int i = 0; i < bots.Count; i++)
            {
                if (collision.ContainsKey((bots[i].row, bots[i].col)))
                    collision[(bots[i].row, bots[i].col)]++;
                else
                    collision[(bots[i].row, bots[i].col)] = 1;
                int pointR = points[routes[bots[i].id, bots[i].target] - 1, 0];
                int pointC = points[routes[bots[i].id, bots[i].target] - 1, 1];
                if (bots[i] == (pointR, pointC))
                {
                    if (bots[i].target + 1 >= routes.GetLength(1)) //더 갈 곳이 없다면 제거
                    {
                        bots.Remove(bots[i]);
                        i -= 1;
                        continue;
                    }

                    bots[i].target++;
                    pointR = points[routes[bots[i].id, bots[i].target] - 1, 0];
                    pointC = points[routes[bots[i].id, bots[i].target] - 1, 1];
                }

                if (bots[i].row > pointR) bots[i] += Bot.direction[1];
                else if (bots[i].row < pointR) bots[i] += Bot.direction[0];
                else if (bots[i].col > pointC) bots[i] += Bot.direction[3];
                else if (bots[i].col < pointC) bots[i] += Bot.direction[2];
            }

            foreach (int value in collision.Values)
            {
                if (value > 1) answer++;
            }
        }

        return answer;
    }

    class Bot
    {
        public int row;
        public int col;
        public int target { get; set;}
        public int id;
        public static Bot[] direction = [new Bot(1, 0), new Bot(-1, 0), new Bot(0, 1), new Bot(0, -1)];

        public Bot(int _row, int _col)
        {
            row = _row;
            col = _col;
        }

        public static Bot operator +(Bot left, Bot right)
        {
            return new Bot(left.row + right.row, left.col + right.col) {target = left.target, id = left.id};
        }

        public static bool operator ==(Bot left, Bot right)
        {
            return left.row == right.row && left.col == right.col;
        }

        public static bool operator !=(Bot left, Bot right)
        {
            return !(left == right);
        }

        public static bool operator ==(Bot left, (int row, int col) right)
        {
            return left.row == right.row && left.col == right.col;
        }

        public static bool operator !=(Bot left, (int row, int col) right)
        {
            return !(left == right);
        }
    }
}