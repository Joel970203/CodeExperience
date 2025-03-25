#include <string>
#include <vector>

using namespace std;

void quad(int y,int x,const vector<vector<int>> &arr, vector<int> &answer,int cnt)
{
    bool isSame = true;
    int check = arr[y][x]; 
    for(int i=y;i<y+cnt;i++)
    {
        for(int j=x;j<x+cnt;j++)
        {
            if(arr[i][j] != check)
            {
                isSame = false;
                break;
            }
        }
        if(!isSame) break;
    }
    
    if(isSame)
    {
        answer[check] += 1;
        return;
    }
    
    
    int div = cnt/2;
    
    quad(y,x,arr,answer,div);
    quad(y,x+div,arr,answer,div);
    quad(y+div,x,arr,answer,div);
    quad(y+div,x+div,arr,answer,div);
}

vector<int> solution(vector<vector<int>> arr) 
{
    int cnt = arr.size();
    vector<int> answer(2,0);
    quad(0,0,arr,answer,cnt);
    return answer;
}