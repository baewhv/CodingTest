using System;

class Program
{
    static public void Main(string[] args)
    {
        int num = int.Parse(Console.ReadLine());
        string[] line = Console.ReadLine().Split(' ');
        int target = int.Parse(Console.ReadLine());
        int count = 0;
        for(int i = 0; i < num; i++)
        {
            if(target == int.Parse(line[i]))
                count++;
        }
        Console.WriteLine(count);
    }
}