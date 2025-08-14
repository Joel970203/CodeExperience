#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    queue<pair<string,string>> q;
    unordered_map<string,string> umap;
    
    for(const auto &cur : record)
    {
        string action,id,name;
        istringstream iss(cur);
        iss >> action >> id >> name;
        
        if(action == "Enter")
        {
            umap[id] = name;
            q.push({id,action});
            
        }
        
        else if(action == "Change")
        {
            umap[id] = name;
        }
        
        else 
        {
            q.push({id,action});
        }
    }
    
    while(!q.empty())
    {
        string tempID = q.front().first;
        string tempAction = q.front().second;
        q.pop();
        
        string k = umap[tempID] + "님이";
        string p;
        if(tempAction == "Enter")
        {
            p = " 들어왔습니다.";
        }
        else 
        {
            p = " 나갔습니다.";
        }
        
        k += p;
        
        answer.push_back(k);
    }
    
    return answer;
}