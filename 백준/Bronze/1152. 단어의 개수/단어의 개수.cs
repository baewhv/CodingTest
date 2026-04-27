using System;

class Program
{
    static void Main(string[] args)
    {
        string[] data = Console.ReadLine().Split(' ');
        int answer = 0;
        for(int i = 0; i < data.Length; i++)
        {
            if(data[i] != "")
            {
                answer++;
            }
        }
        Console.WriteLine(answer);
    }
}