using System;
using System.Collections.Generic;
using System.Text;

public class BOJ9012
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        var sb = new StringBuilder();
        
        for (int i = 0; i < N; i++)
        {
            string s = Console.ReadLine();
            var st = new Stack<char>();
            bool isVPS = true;
            foreach (char c in s)
            {
                if (c == '(')
                {
                    st.Push(c);
                }
                
                else if (c == ')')
                {
                    if (st.Count > 0) st.Pop();
                    else
                    {
                        isVPS = false;
                        break;
                    }
                }
                
            }
            if (st.Count == 0 && isVPS) sb.AppendLine("YES");
            else sb.AppendLine("NO");
        }
        Console.Write(sb.ToString());
    }
}
