#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int room[1450] = {0};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i=0;i<book_time.size();i++)
    {
        int s_time = stoi(book_time[i][0].substr(0,2)) * 60 + stoi(book_time[i][0].substr(3));
        int e_time = stoi(book_time[i][1].substr(0,2)) * 60 + stoi(book_time[i][1].substr(3)) + 10;
        
        for(int j=s_time;j<e_time;j++)
        {
            room[j]++;
        }
        
        for(int i=0;i<1440;i++)
        {
            answer = max(answer,room[i]);
        }

    }
    
    return answer;
}