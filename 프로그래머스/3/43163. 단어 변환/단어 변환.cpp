#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[50] = {false};

int BFS(const string &begin,const string &target,const vector<string> &words)
{
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    while(!q.empty())
    {
        string key = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for(int i=0;i<words.size();i++)
        {
            int temp_cnt = 0;
            for(int j=0;j<key.length();j++)
            {
                if(key[j] != words[i][j]) temp_cnt++;
            }
            
            if(temp_cnt == 1)
            {
                if(words[i] == target)
                {
                    return cnt+1;
                }
                
                else
                {
                    q.push({words[i],cnt+1});
                }
            }
        }
    }
    
    return 0;
    
}

int solution(string begin, string target, vector<string> words) 
{
    bool isThere = false;
    int answer;
    for(int i=0;i<words.size();i++)
    {
        if(words[i] == target)
        {
            isThere = true;
            break;
        }
    }
    if(isThere)
    {
        answer = BFS(begin,target,words);
    }
    
    else
    {
        answer = 0;
    }
    return answer;
}