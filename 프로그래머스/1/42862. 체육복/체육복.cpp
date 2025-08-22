#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    
    vector<pair<int,int>> students(n+1);
    students[0]={0,0};
    
    for(int i=1;i<=n;++i)
    {
        students[i] = {i,1};
    }
    
    for(int i=0;i<lost.size();++i)
    {
        students[lost[i]].second--;
    }

    for(int i=0;i<reserve.size();++i)
    {
        students[reserve[i]].second++;
    }
    
    for(int i=1;i<students.size();++i)
    {
        if(students[i].second == 0)
        {
            if(students[i-1].second >= 2)
            {
                students[i-1].second--;
                students[i].second++;
            }

            else if(students[i+1].second >= 2)
            {
                students[i+1].second--;
                students[i].second++;
            }
        }
    }
    
    for(int i=1;i<=students.size();++i)
    {
        if(students[i].second >= 1) answer++;
    }
    
    
    return answer;
}