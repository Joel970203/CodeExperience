using System; 
using System.Text; 
public class BOJ10871 
{ 
    public static void Main() 
    { 
        string[] input = Console.ReadLine().Split(); 
        int N = int.Parse(input[0]); 
        int X = int.Parse(input[1]); 
        string[] arr = Console.ReadLine().Split(); 
        StringBuilder sb = new StringBuilder(); 
        for (int i = 0; i < N; i++) 
        { 
            int tmp = int.Parse(arr[i]); 
            if (tmp < X) 
            { 
                sb.Append(tmp).Append(' '); 
                         
            } 
        } 
        Console.WriteLine(sb.ToString().Trim()); 
    } 
}