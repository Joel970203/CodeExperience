#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

// 인출 횟수 계산 함수
bool isPossible(int K, vector<int>& cost, int M) {
    int count = 1; // 처음에 1번 인출
    int current = K; // 현재 남은 금액

    for (int i = 0; i < cost.size(); i++) {
        if (current < cost[i]) { 
            // 현재 남은 금액으로는 하루를 지날 수 없으면 다시 인출
            count++;
            current = K; // 다시 K원을 인출

            // 인출 횟수가 M을 넘으면 불가능하므로 false 반환
            if (count > M) return false;
        }
        // 현재 금액에서 오늘 쓸 돈을 차감
        current -= cost[i];
    }

    return true; // M번 이하로 인출이 가능하면 true
}

int main() {
    fastio();
    
    int N, M;
    cin >> N >> M;

    vector<int> cost(N);
    int maxCost = 0; // 인출 금액의 하한
    int totalCost = 0; // 인출 금액의 상한

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        maxCost = max(maxCost, cost[i]); // 각 날의 최대 금액 중 최댓값
        totalCost += cost[i]; // 모든 금액의 총합
    }

    // 이분 탐색 범위 설정
    int low = maxCost;
    int high = totalCost;
    int answer = totalCost;

    // 이분 탐색 시작
    while (low <= high) {
        int mid = (low + high) / 2; // 중간값(K 값) 설정

        if (isPossible(mid, cost, M)) {
            // M번 이하로 인출 가능하면 K를 더 줄여봄
            answer = mid;
            high = mid - 1;
        } else {
            // M번 이하로 인출 불가능하면 K를 더 키움
            low = mid + 1;
        }
    }

    // 최소 인출 금액 출력
    cout << answer << "\n";

    return 0;
}
