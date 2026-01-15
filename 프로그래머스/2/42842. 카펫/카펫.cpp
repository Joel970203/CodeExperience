#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    vector<pair<int,int>> couple;

    
    int cube = brown + yellow;
    
    for(int i=3;i<=cube;i++)
    {
        if((cube % i) == 0)
        {
            couple.push_back({i,(cube/i)}); // 가로,세로 
        }
    }
    

    
    for(int i=0;i<couple.size();i++)
    {
        int width = couple[i].first;
        int height = couple[i].second;
        
        if(width < height) continue;
        
        int guess = width * 2 + (height - 2) * 2;
        
        if(guess == brown) 
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    
    return answer;
}