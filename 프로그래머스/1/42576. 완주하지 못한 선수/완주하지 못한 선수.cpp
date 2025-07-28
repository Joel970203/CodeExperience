#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    unordered_map<string,int> u_map;
    
    for(int i=0;i<participant.size();i++)
    {
        u_map[participant[i]]++;
    }
    
    for(int i=0;i<completion.size();i++)
    {
        u_map[completion[i]]--;
    }
    
    for(const auto& cursor : u_map)
    {
        if(cursor.second > 0)
        {
            return cursor.first;
        }
    }
}