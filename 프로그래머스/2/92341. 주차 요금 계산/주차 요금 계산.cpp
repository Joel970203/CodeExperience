#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int timeToMinutes(string time)
{
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return hour * 60 + minute;
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
   map<string, int> parkingTime; // 차량 번호별 총 주차 시간
    map<string, int> inTime;      // 차량 입차 시간

    for (const string &record : records)
    {
        stringstream ss(record);
        string time, car, action;
        ss >> time >> car >> action;

        int minutes = timeToMinutes(time);

        if (action == "IN") 
        {
            inTime[car] = minutes;
        }
        else 
        { 
            int duration = minutes - inTime[car];
            parkingTime[car] += duration;
            inTime.erase(car);
        }
    }

    for (auto &[car, time] : inTime) 
    {
        parkingTime[car] += (23 * 60 + 59) - time;
    }

    vector<pair<string, int>> sortedFees(parkingTime.begin(), parkingTime.end());
    sort(sortedFees.begin(), sortedFees.end());

    vector<int> answer;
    for (auto &[car, time] : sortedFees) 
    {
        int total_fee = fees[1]; 

        if (time > fees[0])
        { 
            total_fee += ceil((time - fees[0]) / (double)fees[2]) * fees[3];
        }

        answer.push_back(total_fee);
    }

    return answer;
}
