#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    vector<vector<pair<int,int>>> graph(n);
    
    for(const auto& cur : costs)
    {
        graph[cur[0]].push_back({cur[2],cur[1]});
        graph[cur[1]].push_back({cur[2],cur[0]});
    }
    
    vector<bool> visited(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0}); // cost , node 
    int answer = 0;
    while(!pq.empty())
    {
        auto [cost,node] = pq.top(); pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        answer += cost;
        
        for(const auto& cur : graph[node])
        {
            pq.push(cur);
        }
    }
    return answer;
}