#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);

    // 회의 정보 입력
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0;
    int lastEndTime = 0;

    for (const auto& meeting : meetings) {
        if (meeting.first >= lastEndTime) {
            // 현재 회의의 시작 시간이 이전 회의의 끝나는 시간 이후일 때 선택
            lastEndTime = meeting.second;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
