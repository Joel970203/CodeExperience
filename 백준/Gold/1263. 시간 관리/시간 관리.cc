#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> order;

    for (int i = 0; i < N; i++) 
    {
        int duration, deadline;
        cin >> duration >> deadline;
        order.push_back({ duration, deadline });
    }

    sort(order.begin(), order.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    int current_time = order[0].second;  // 가장 늦은 마감 시간부터 시작

    for (const auto& task : order) 
    {
        current_time = min(current_time, task.second) - task.first;
        if (current_time < 0) 
        {  // 시간을 초과한 경우
            cout << -1 << endl;
            return 0;
        }
    }

    cout << current_time << endl;
}
