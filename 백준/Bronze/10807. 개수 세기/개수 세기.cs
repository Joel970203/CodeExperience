using System;

public class BOJ10807
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        string[] input = Console.ReadLine().Split();
        int v = int.Parse(Console.ReadLine());

        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (int.Parse(input[i]) == v)
                count++;
        }

        Console.WriteLine(count);
    }
}
