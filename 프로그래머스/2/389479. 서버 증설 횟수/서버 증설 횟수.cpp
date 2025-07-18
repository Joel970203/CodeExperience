#include <string>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server = 0;
    queue<pair<int,int>> q; // 반납해야하는 시간, 서버갯수
    
    for(int i=0;i<players.size();i++)
    {
        if(!q.empty() && q.front().first == i) 
        {
            server -= q.front().second;
            q.pop();
        }
        
        if(players[i] >= m)
        {
            int capacity = players[i] / m;
            if(server < capacity)
            {
                int add = capacity - server;
                server += add;
                answer += add;
                q.push({i+k,add});
            }
            
        }
        
    }
    
    return answer;
}