#include <string>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &computers, vector<bool> &visited,int n,int k)
{
    visited[k] = true;
    
    for(int i=0;i<computers[k].size();i++)
    {
        if(visited[i] == false && computers[k][i] == 1)
        {
            dfs(computers,visited,n,i);
        }
    }
}
    
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            dfs(computers,visited,n,i);
            answer++;
        }
    }

    return answer;
}