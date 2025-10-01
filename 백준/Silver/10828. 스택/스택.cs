using System;
using System.Collections.Generic;
using System.Text; // ← 추가

public class BOJ10828
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        var st = new Stack<int>();
        var sb = new StringBuilder();

        for (int i = 0; i < N; i++)
        {
            string[] tokens = Console.ReadLine().Split();

            switch (tokens[0])
            {
                case "push":
                {
                    int x = int.Parse(tokens[1]); // 블록으로 감싸서 지역 변수 안전
                    st.Push(x);
                    break;
                }
                case "pop":
                {
                    sb.AppendLine(st.Count == 0 ? "-1" : st.Pop().ToString());
                    break;
                }
                case "size":
                {
                    sb.AppendLine(st.Count.ToString());
                    break;
                }
                case "empty":
                {
                    sb.AppendLine(st.Count == 0 ? "1" : "0");
                    break;
                }
                case "top":
                {
                    sb.AppendLine(st.Count == 0 ? "-1" : st.Peek().ToString());
                    break;
                }
            }
        }

        Console.Write(sb.ToString());
    }
}
