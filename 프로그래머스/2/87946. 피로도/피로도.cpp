#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = 0;
    vector<int> arr;
    for(int i=0;i<dungeons.size();i++)
    {
        arr.push_back(i);
    }
    
    do
    {
        int fatigue = k;
        int count = 0;
        for(int idx : arr)
        {
            int need = dungeons[idx][0];
            int cost = dungeons[idx][1];
            if(fatigue >= need)
            {
                fatigue -= cost;
                count++;
            }
            else break;
        }
        answer = max(answer,count);
    }while(next_permutation(arr.begin(),arr.end()));
    
    return answer;
}