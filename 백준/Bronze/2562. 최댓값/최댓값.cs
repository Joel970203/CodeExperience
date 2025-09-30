using System;

public class BOJ2562
{
    public static void Main()
    {
        int max = int.MinValue;
        int idx = -1;
        
        for(int i=1;i<=9;i++)
        {
            int num = int.Parse(Console.ReadLine());
            if(num > max)
            {
                max = num;
                idx = i;
            }
        }
        Console.WriteLine(max);
        Console.WriteLine(idx);
    }
}