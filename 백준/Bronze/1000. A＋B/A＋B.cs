using System;
using System.Collections.Generic;

public class BOJ1000
{
    public static void Main()
    {
        string[] txt = Console.ReadLine().Split();
        
        int A = int.Parse(txt[0]);
        int B = int.Parse(txt[1]);
        
        Console.WriteLine(A+B);
    }
}