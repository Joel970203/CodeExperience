#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;  
    int current_weight = 0; 
    queue<pair<int, int>> bridge;  // 다리를 건너는 트럭 {무게, 남은 시간}

    int i = 0;  // 대기 트럭의 인덱스
    while (true) 
    {
        time++;
        // 1. 다리를 건너는 트럭의 남은 시간을 감소
        if (!bridge.empty() && bridge.front().second == 0) 
        {
            current_weight -= bridge.front().first;  // 다리를 건넌 트럭 무게 제거
            bridge.pop();
        }

        // 2. 대기 트럭이 다리에 올라갈 수 있는지 확인
        if (i < truck_weights.size() && current_weight + truck_weights[i] <= weight && bridge.size() < bridge_length) 
        {
            bridge.push({truck_weights[i], bridge_length});  // 트럭을 다리에 올림
            current_weight += truck_weights[i];  // 다리 위 무게 갱신
            i++;  // 대기 트럭 인덱스 증가
        }

        // 3. 모든 트럭이 다리를 건넜다면 종료
        if (bridge.empty() && i >= truck_weights.size()) 
        {
            break;
        }

        // 4. 다리 위 트럭의 남은 시간을 처리
        queue<pair<int, int>> temp_bridge;
        while (!bridge.empty()) 
        {
            auto truck = bridge.front();
            bridge.pop();
            temp_bridge.push({truck.first, truck.second - 1});
        }
        swap(bridge, temp_bridge);
    }

    return time;
}
