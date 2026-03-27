using System;

class Program
{
    static void Main(string[] args)
    {
        int x = int.Parse(Console.ReadLine());
        int y = int.Parse(Console.ReadLine());
        
        
        Console.WriteLine(1 + (x * y < 0 ? 1 : 0) + (y < 0 ? 2 : 0));
    }
}