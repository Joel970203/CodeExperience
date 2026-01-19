#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<pair<int,int>> q;
    int sz = progresses.size();
    
    for(int i=0;i<sz;++i)
    {
        q.push({progresses[i],i});
    }
    
    while(!q.empty())
    {
        int qsz = q.size();
        
        for(int i=0;i<qsz;++i)
        {
            auto[pro,idx] = q.front(); q.pop();
            int tmp = pro + speeds[idx];
            q.push({tmp,idx});
        }
        
        int cnt = 0;
        
        while(!q.empty() && q.front().first >= 100)
        {
            cnt++;
            q.pop();
        }
        
        if(cnt >0 ) answer.push_back(cnt);
        
    }
    
    return answer;
}