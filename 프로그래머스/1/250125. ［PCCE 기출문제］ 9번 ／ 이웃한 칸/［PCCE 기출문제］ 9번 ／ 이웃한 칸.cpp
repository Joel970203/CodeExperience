#include <string>
#include <vector>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int solution(vector<vector<string>> board, int h, int w) 
{
    int answer = 0;
    
    int sizeX = board[0].size();
    int sizeY = board.size();
    string color = board[h][w];
    for(int i=0;i<4;i++)
    {
        int tempX = w;
        int tempY = h;
        tempX += dx[i];
        tempY += dy[i];
        
        if(tempX < sizeX && tempX >= 0 && tempY < sizeY && tempY >= 0) 
        {
            if(board[tempY][tempX] == color)
            {
                answer++;
            }
        }
    }
    
    return answer;
}