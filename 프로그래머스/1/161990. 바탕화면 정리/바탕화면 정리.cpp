#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    vector<int> answer;
    int lux = 51; 
    int luy = 51;
    int rdx = -1; 
    int rdy = -1;
    
    for(int i=0;i<wallpaper.size();i++) // 3번
    {
        for(int j=0;j<wallpaper[0].size();j++)
        {
            if(wallpaper[i][j] == '#')
            {
                lux = min(i,lux);
                luy = min(j,luy);
                rdx = max(i+1,rdx);
                rdy = max(j+1,rdy);
            }
        }
    }
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    
    return answer;
}