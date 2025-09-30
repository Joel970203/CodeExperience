using System;

public class BOJ1157
{
    public static void Main()
    {
        string txt = Console.ReadLine().ToUpperInvariant();

        int[] cnt = new int[26];
        foreach (char ch in txt)
        {
            if (ch >= 'A' && ch <= 'Z')
                cnt[ch - 'A']++;
        }

        int max = -1, idx = -1;
        bool tie = false;

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > max)
            {
                max = cnt[i];
                idx = i;
                tie = false;            // 새 최대값이면 동률 해제
            }
            else if (cnt[i] == max)
            {
                tie = true;             // 같은 최대값이 또 나오면 동률
            }
        }

        Console.WriteLine(tie ? "?" : ((char)('A' + idx)).ToString());
    }
}
