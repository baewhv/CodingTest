using System;

class Program
{
    static void Main(string[] args)
    {
        int StartNum = int.Parse(Console.ReadLine());
        int CurrentNum = StartNum;
        int Circle = 0;
        
        while(StartNum != CurrentNum || Circle == 0)
        {
            int NumA = CurrentNum;
            if (NumA < 10)
            {
                NumA *= 10;
            }
            int NumB = NumA / 10 + NumA % 10; // 각 자릿수 더하기.
            CurrentNum = (CurrentNum % 10) * 10 + NumB % 10;
            Circle++;
        }
        
        Console.WriteLine(Circle);
    }
}