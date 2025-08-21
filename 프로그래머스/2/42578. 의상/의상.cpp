#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    unordered_map<string,int> u_map;
    
    for(int i=0;i<clothes.size();i++)
    {
        u_map[clothes[i][1]]++;
    }
    
    // 헤드기어 
    // 아이웨어 1 
    
    for(const auto &cur : u_map)
    {
        answer *= cur.second + 1;
    }
    
    return answer-1;
}