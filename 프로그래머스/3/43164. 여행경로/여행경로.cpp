#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<bool> used;
bool found = false;

void DFS(const vector<vector<string>> &tickets,int cnt,string city,vector<string> &path)
{
    path.push_back(city);
    
    if(cnt == tickets.size())
    {
        answer = path;
        found = true;
        return;
    }
    
    // [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]
    for(int i=0;i<tickets.size();i++)
    {
        if(!used[i] && tickets[i][0] == city)
        {
            used[i] = true;
            DFS(tickets,cnt+1,tickets[i][1],path);
            if(found) return;
            used[i] = false;
        }
    }
    path.pop_back();
}
    
vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> path;
    int cnt = 0;
    used.resize(tickets.size(),0);
    sort(tickets.begin(),tickets.end());
    DFS(tickets,cnt,"ICN",path);
    return answer;
}