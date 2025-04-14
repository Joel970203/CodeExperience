#include <string>
#include <vector>

using namespace std;



void recursive(const vector<vector<int>> &arr,vector<int> &answer,int offset,int y,int x)
{
    bool isSame = true;
    int chk = arr[y][x];
    for(int i=y;i<y+offset;i++)
    {
        for(int j=x;j<x+offset;j++)
        {
            if(arr[i][j] != chk)
            {
                isSame = false;
            }
            
            if(!isSame)
            {
                break;
            }
        }
        if(!isSame)
        {
            break;
        }
    }
    
    if(isSame)
    {
        answer[chk]++;
        return;
    }
    
    offset /= 2;
    
    recursive(arr,answer,offset,y,x);
    recursive(arr,answer,offset,y+offset,x);
    recursive(arr,answer,offset,y,x+offset);
    recursive(arr,answer,offset,y+offset,x+offset);
}

vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer = {0,0};
    int offset = arr.size();
    recursive(arr,answer,offset,0,0);
    return answer;
}