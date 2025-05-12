#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    unordered_map<int, int> freq;
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        freq[tangerine[i]]++;
    }
    
    vector<int> arr;
    for(const auto& [key, value] : freq)
    {
        arr.push_back(value);
    }
    
    sort(arr.begin(), arr.end(), [](int a, int b)
    {
        return a > b; 
    });
    
    int cnt = 0, answer = 0;
    
    for(const auto cursor : arr)
    {
        cnt += cursor;
        answer++;
        if(cnt >= k)
        {
            break;
        }
    }

    return answer; 
}
