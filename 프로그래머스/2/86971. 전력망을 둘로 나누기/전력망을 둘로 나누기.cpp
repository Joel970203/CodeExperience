#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int bfs(int start,const vector<vector<int>> &graph,int n)
{
    vector<bool> visited(n+1,0);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int next : graph[cur])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = n-1;
    for(int i=0;i<wires.size();++i)
    {
        vector<vector<int>> graph(n+1);
        for(int j=0;j<wires.size();++j)
        {
            if(i==j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        int cnt = bfs(wires[i][0],graph,n);
        int diff = abs(n-2*cnt);
        answer = min(answer,diff);
    }
    
    return answer;
}