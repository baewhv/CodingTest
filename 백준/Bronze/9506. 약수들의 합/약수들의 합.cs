using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        while (true)
        {
            int input = int.Parse(Console.ReadLine());
            if (input == -1) break;
            int sum = 0;
            Queue<int> q = new Queue<int>();
            for (int i = 1; i <= input / 2; i++)
            {
                if (input % i == 0)
                {
                    sum += i;
                    q.Enqueue(i);
                }
            }
            Console.Write(input);
            if (input == sum)
            {
                Console.Write(" =");
                while (true)
                {
                    Console.Write($" {q.Dequeue()}");
                    if (q.Count != 0) Console.Write(" +");
                    else break;
                }
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine(" is NOT perfect.");
            }
        }

    }
}