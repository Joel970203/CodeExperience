#include <string>
#include <vector>
#include <queue>

using namespace std;

#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int cur_weight = 0;
    int time = 0;
    int idx = 0;

    // 처음엔 다리가 비어있으니 0으로 채워두는 방식 (선택)
    for (int i = 0; i < bridge_length; i++) bridge.push(0);

    while (idx < (int)truck_weights.size()) {
        time++;

        // 1) 한 칸 전진: 앞에서 빠져나감
        cur_weight -= bridge.front();
        bridge.pop();

        // 2) 다음 트럭을 올릴 수 있나?
        int next = truck_weights[idx];
        if (cur_weight + next <= weight) {
            bridge.push(next);
            cur_weight += next;
            idx++;               //  트럭을 실제로 올렸을 때만 idx 증가
        } else {
            bridge.push(0);      //  못 올리면 빈 칸(0) 넣어서 시간만 흐르게
        }
    }

    // 마지막 트럭이 올라간 뒤 다리를 빠져나가는 시간
    time += bridge_length;
    return time;
}
