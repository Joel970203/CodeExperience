#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    int n = sequence.size();
    int start = 0, end = 0; 
    int current_sum = 0;    
    int min_length = n + 1; 
    vector<int> result(2, -1); 

    while (end < n) 
    {
        current_sum += sequence[end];
        while (current_sum >= k) 
        {
            if (current_sum == k) 
            {
                int length = end - start + 1;
                if (length < min_length) 
                {
                    min_length = length;
                    result = {start, end}; 
                }
            }
            current_sum -= sequence[start];
            start++;
        }
        end++;
    }

    return result;
}