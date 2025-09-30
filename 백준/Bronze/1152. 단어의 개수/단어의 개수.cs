using System;

public class BOJ1152
{
    public static void Main()
    {
        string s = Console.ReadLine();
        int cnt = 0;
        bool inWord = false;

        foreach (char c in s)
        {
            if (c == ' ')            
                inWord = false;
            else                    
            {
                if (!inWord) cnt++; 
                inWord = true;
            }
        }

        Console.WriteLine(cnt);
    }
}
