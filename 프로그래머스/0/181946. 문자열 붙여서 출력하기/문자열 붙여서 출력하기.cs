using System;

public class Example
{
    public static void Main()
    {
        String[] input;

        Console.Clear();
        input = Console.ReadLine().Split(' ');

        String s1 = input[0];
        String s2 = input[1];
        
        String s3 = s1+s2;
        
        Console.WriteLine(s3);
    }
}