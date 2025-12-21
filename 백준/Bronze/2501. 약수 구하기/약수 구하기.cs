using System;

class program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int K = int.Parse(input[1]);
        int num = 0;
        for (int i = 1; i <= N; i++)
        {
            if (N % i == 0)
            {
                num++;
                if (num == K)
                {
                    Console.WriteLine(i);
                    return;
                }
            }
        }
        if (num < K)
        {
            Console.WriteLine(0);
        }
    }
}