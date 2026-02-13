using System;

class program
{
    static void Main(string[] args)
    {
        string[] temp = Console.ReadLine().Split(' ');
        int a = int.Parse(temp[0]);
        int b = int.Parse(temp[1]);
        Console.WriteLine(a+b);
    }
}