#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int currentday = startday;
    int prize;
    
    for(int i=0;i<timelogs.size();i++)
    {
        prize = 0;
        int time_calc = schedules[i]+10;
        if((time_calc % 100) >= 60)
        {
            time_calc -= 60;
            time_calc += 100;
        }
        for(int j=0;j<timelogs[i].size();j++)
        {
            if(time_calc < timelogs[i][j])
            {
                if(currentday >= 6)
                {
                  prize++;
                }
                
            }
            else
            {
                prize++;
            }
            if(currentday < 7)
            {
                currentday++;
            }
            else currentday = 1;
        }
        
        if(prize==7)
        {
            answer++;
        }
    }
    return answer;
}