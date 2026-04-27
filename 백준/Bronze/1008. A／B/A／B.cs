using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        double[] answer = Console.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
        Console.WriteLine(answer[0]/answer[1]);
        return;
    }
}