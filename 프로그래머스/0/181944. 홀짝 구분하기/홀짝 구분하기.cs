using System;

public class Example
{
    public static void Main()
    {
        String[] s;

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        
        Console.Write($"{a} is {a % 2 == 0 ? "even" : "odd"}");
    }
}