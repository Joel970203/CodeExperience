#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int start, int end, vector<int>& order, vector<int>& picks, vector<string>& minerals) {
    if (start == end) { // 순열 완성
        int k = 0;
        for (int i = 0; i < end; i++) {
            for (int j = 0; j < 5; j++) {
                int idx = i * 5 + j;
                if (idx >= minerals.size()) { // 범위 초과 방지
                    break;
                }

                if (minerals[idx] == "diamond") {
                    if (order[i] == 0) k += 1;       // 다이아 곡괭이
                    else if (order[i] == 1) k += 5;  // 철 곡괭이
                    else if (order[i] == 2) k += 25; // 돌 곡괭이
                } else if (minerals[idx] == "iron") {
                    if (order[i] == 0) k += 1;       // 다이아 곡괭이
                    else if (order[i] == 1) k += 1;  // 철 곡괭이
                    else if (order[i] == 2) k += 5;  // 돌 곡괭이
                } else { // "stone"
                    k += 1; // 모든 곡괭이 동일
                }
            }
        }
        return k; // 계산된 피로도 반환
    }

    int minimum = 1e9; // 최솟값 초기화
    for (int i = 0; i < 3; i++) {
        if (picks[i] > 0) {
            picks[i]--;            // 곡괭이 사용
            order[start] = i;      // 현재 선택한 곡괭이 기록
            minimum = min(minimum, dfs(start + 1, end, order, picks, minerals));
            picks[i]++;            // 곡괭이 복구
        }
    }
    return minimum;
}

int solution(vector<int> picks, vector<string> minerals) {
    int m = minerals.size();
    int cnt = 0;

    // m을 5로 나누어 작업 그룹 수 계산
    while (m > 0) {
        m -= 5;
        cnt++;
    }

    // 사용 가능한 곡괭이 개수를 제한
    cnt = min(cnt, picks[0] + picks[1] + picks[2]);

    vector<int> order(cnt, 0); // `cnt`에 맞게 초기화
    return dfs(0, cnt, order, picks, minerals); // 최솟값 반환
}
