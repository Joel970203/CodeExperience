#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

// 주어진 시간(mid) 내에 M명을 처리할 수 있는지 확인하는 함수
bool isPossible(long long mid, vector<int>& Tk, int M) {
    long long count = 0;  // 처리할 수 있는 총 인원 수

    for (int i = 0; i < Tk.size(); i++) {
        count += mid / Tk[i];  // 각 심사대에서 mid 시간 내에 처리할 수 있는 인원 수 계산
        if (count >= M) return true;  // M명 이상을 처리할 수 있으면 true 반환
    }

    return count >= M;
}

int main() {
    fastio();

    int N, M;
    cin >> N >> M;

    vector<int> Tk(N);
    for (int i = 0; i < N; i++) {
        cin >> Tk[i];
    }

    // 이분 탐색 범위 설정
    long long low = 1;  // 최소 1초는 필요하므로
    long long high = (long long)*max_element(Tk.begin(), Tk.end()) * M;  // 최대 시간: 가장 느린 심사대 * M명
    long long ans = high;

    // 이분 탐색
    while (low <= high) {
        long long mid = (low + high) / 2;  // 중간 시간(mid) 설정

        if (isPossible(mid, Tk, M)) {
            ans = mid;  // 가능한 시간이면 일단 정답으로 저장하고 더 작은 시간도 확인
            high = mid - 1;
        }
        else {
            low = mid + 1;  // 불가능하면 시간을 늘려야 함
        }
    }

    // 최종적으로 모든 사람이 심사를 받을 수 있는 최소 시간을 출력
    cout << ans << "\n";

    return 0;
}