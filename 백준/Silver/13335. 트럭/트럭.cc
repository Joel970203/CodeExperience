#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, w, L;
    cin >> n >> w >> L;

    vector<int> trucks(n);
    for (int i = 0; i < n; i++) cin >> trucks[i];

    queue<int> bridge; // 다리 상태
    int time = 0;
    int weight = 0;
    int idx = 0; // 다음 트럭

    // 다리 길이만큼 0으로 초기화
    for (int i = 0; i < w; i++) bridge.push(0);

    while (!bridge.empty()) {
        time++;

        // 다리에서 나가는 트럭
        weight -= bridge.front();
        bridge.pop();

        if (idx < n) {
            // 다음 트럭이 올라갈 수 있으면
            if (weight + trucks[idx] <= L) {
                bridge.push(trucks[idx]);
                weight += trucks[idx];
                idx++;
            }
            else {
                // 못 올라가면 빈칸
                bridge.push(0);
            }
        }
    }

    cout << time << "\n";
}
