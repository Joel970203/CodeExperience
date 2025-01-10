#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> arr;
int cnt = 0;

// 백트래킹 함수
void backtrack(int index, int current_sum) {
    // 부분 수열의 크기가 0보다 커야 하므로, 합이 S가 될 때만 카운트
    if (index > 0 && current_sum == S) {
        cnt++;
    }

    for (int i = index; i < N; i++) {
        // 현재 원소를 포함시키고 재귀 호출
        backtrack(i + 1, current_sum + arr[i]);
    }
}

int main() {
    cin >> N >> S;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 백트래킹 시작 (인덱스 0, 현재 합 0)
    backtrack(0, 0);

    cout << cnt << endl; // 결과 출력

    return 0;
}