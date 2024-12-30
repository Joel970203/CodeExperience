#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool cmp(const vector<pair<string, pair<int, int>>> &a, const vector<pair<string, pair<int, int>>> &b) 
{
    return a[0].second.first < b[0].second.first;
}

vector<string> solution(vector<vector<string>> plans) 
{
    vector<string> answer;
    stack<pair<string, int>> st; // 멈춰둔 과제의 스택
    vector<vector<pair<string, pair<int, int>>>> my_plans; // 과제 정보 저장

    // plans를 처리하여 my_plans에 저장
    for (const auto& plan : plans) 
    {
        string name = plan[0];
        string head = plan[1].substr(0, 2);
        string tail = plan[1].substr(3, 2);
        int startTime = stoi(head) * 60 + stoi(tail); // 시작 시간(분 단위)
        int duration = stoi(plan[2]); // 소요 시간
        my_plans.push_back({{name, {startTime, duration}}});
    }

    // 시작 시간을 기준으로 정렬
    sort(my_plans.begin(), my_plans.end(), cmp);

    int currentTime = 0; // 현재 시간
    for (int i = 0; i < my_plans.size(); ++i) 
    {
        const auto& currentTask = my_plans[i];
        string taskName = currentTask[0].first;
        int startTime = currentTask[0].second.first;
        int duration = currentTask[0].second.second;

        // 진행 중인 과제를 끝내거나 멈추기
        while (!st.empty() && currentTime < startTime) 
        {
            auto [pausedName, pausedTime] = st.top();
            st.pop();

            if (currentTime + pausedTime <= startTime)
            {
                // 멈춰둔 과제를 끝낼 수 있음
                currentTime += pausedTime;
                answer.push_back(pausedName);
            } 
            
            else 
            {
                // 멈춰둔 과제를 끝낼 수 없음
                st.push({pausedName, pausedTime - (startTime - currentTime)});
                currentTime = startTime;
                break;
            }
        }

        // 새로운 과제 시작
        currentTime = startTime;
        if (i + 1 < my_plans.size()) 
        {
            int nextStartTime = my_plans[i + 1][0].second.first;
            if (currentTime + duration <= nextStartTime) 
            {
                // 현재 과제를 끝낼 수 있음
                currentTime += duration;
                answer.push_back(taskName);
            } 
            else 
            {
                // 현재 과제를 끝낼 수 없음
                st.push({taskName, duration - (nextStartTime - currentTime)});
                currentTime = nextStartTime;
            }
        } 
        
        else 
        {
            // 마지막 과제
            currentTime += duration;
            answer.push_back(taskName);
        }
    }

    // 멈춰둔 과제를 처리
    while (!st.empty()) 
    {
        auto [pausedName, pausedTime] = st.top();
        st.pop();
        answer.push_back(pausedName);
    }

    return answer;
}
