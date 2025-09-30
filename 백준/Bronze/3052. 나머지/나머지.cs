using System;
using System.Collections.Generic;

public class BOJ3052
{
    public static void Main()
    {
        HashSet<int> hash = new HashSet<int>();
        
        for(int i=0;i<10;i++)
        {
            int k = int.Parse(Console.ReadLine())%42;
            hash.Add(k);
        }
        Console.WriteLine(hash.Count);
    }
}