#include <iostream>
#include <algorithm>

#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main() {
    fastio();
    int N;
    cin >> N;

    // 이전 집까지의 최소 비용을 저장할 변수 3개
    int prevR, prevG, prevB;
    
    // 첫 번째 집의 비용 입력 및 초기화
    cin >> prevR >> prevG >> prevB;

    for (int i = 1; i < N; i++) {
        int currR, currG, currB; // 현재 집의 비용
        int r, g, b;            // 현재 집의 각 색상 비용 입력
        cin >> r >> g >> b;

        // 점화식 적용: 이전 상태의 최솟값 + 현재 색상 비용
        currR = min(prevG, prevB) + r;
        currG = min(prevR, prevB) + g;
        currB = min(prevR, prevG) + b;

        // 다음 집을 위해 현재 결과를 이전 결과로 업데이트
        prevR = currR;
        prevG = currG;
        prevB = currB;
    }

    // 마지막에 남은 세 값 중 최솟값이 정답
    cout << min({prevR, prevG, prevB}) << endl;

    return 0;
}