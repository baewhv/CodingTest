using System;

class Program
{
    static void Main(string[] args)
    {
        string word = Console.ReadLine();
        string[] croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
        for(int i = 0; i < croatia.Length; i++)
        {
            word = word.Replace(croatia[i], "_");
        }
        Console.WriteLine(word.Length);
    }
}