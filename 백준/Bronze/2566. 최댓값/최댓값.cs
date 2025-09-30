using System;

public class BOJ
{
    public static void Main()
    {
        int row=0,col=0;
        int max = int.MinValue;
        for(int i=0;i<9;i++)
        {
            string[] s = Console.ReadLine().Split();
            for(int j=0;j<9;j++)
            {
                int num = int.Parse(s[j]);
                if(num > max)
                {
                    max = num;
                    row = i;
                    col = j;
                }
            }
        }
        
        Console.WriteLine(max);
        Console.WriteLine($"{row + 1} {col + 1}");
    }
}