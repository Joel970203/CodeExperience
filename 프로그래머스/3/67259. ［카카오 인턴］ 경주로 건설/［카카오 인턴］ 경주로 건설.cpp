#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;


struct Node {
    int y, x, dir, cost;
};

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int bfs(const vector<vector<int>> &board)
{
    int n = board.size();
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n, vector<int>(4, INT_MAX)));
    queue<Node> q;
    
    for(int i=0; i<4; ++i)
    {
        cost[0][0][i] = 0;
        q.push({0, 0, i, 0});
    }
    
    int answer = INT_MAX;
    
    while(!q.empty())
    {
        auto [y, x, dir, curCost] = q.front();
        q.pop();
        
        if(y == n-1 && x == n-1)
        {
            answer = min(answer, curCost);
            continue;
        }
        
        for(int i=0; i<4; i++)
        {
            int tempY = y + dy[i];
            int tempX = x + dx[i];
            
            if(tempY >= 0 && tempY < n && tempX >=0 && tempX < n)
            {
                if(board[tempY][tempX] == 0)
                {
                    int newCost = curCost + ((dir == i) ? 100 : 600);
                    
                    if (cost[tempY][tempX][i] > newCost) 
                    {
                        cost[tempY][tempX][i] = newCost;
                        q.push({tempY, tempX, i, newCost});
                    }
                }
            }
        }
    }
    return answer;
}


int solution(vector<vector<int>> board) 
{
    int answer = bfs(board);
    return answer;
}