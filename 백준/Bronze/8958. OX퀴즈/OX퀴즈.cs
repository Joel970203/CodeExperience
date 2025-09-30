using System;
using System.Text;

public class BOJ8958
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++)
        {
            string S = Console.ReadLine();
            int cnt = 0;  
            int score = 0; 

            for (int j = 0; j < S.Length; j++)
            {
                if (S[j] == 'O')
                {
                    cnt++;
                    score += cnt;
                }
                else
                {
                    cnt = 0;
                }
            }

            sb.AppendLine(score.ToString());
        }

        Console.Write(sb.ToString());
    }
}
