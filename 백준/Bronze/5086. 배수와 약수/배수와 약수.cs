using System;

class program
{
    static void Main(string[] args)
    {
        while (true)
        {
            string input = Console.ReadLine();
            string[] sArray = input.Split(' ');
            int a = int.Parse(sArray[0]);
            int b = int.Parse(sArray[1]);
            if (a == 0 && b == 0) break;
            if (b % a == 0)
                Console.WriteLine("factor");
            else if (a % b == 0)
                Console.WriteLine("multiple");
            else
                Console.WriteLine("neither");
        }
    }
}