using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        int[] answer = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        Console.WriteLine(answer[0]-answer[1]);
        return;
    }
}