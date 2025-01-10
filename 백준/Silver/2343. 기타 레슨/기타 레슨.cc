#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

// 강의를 M개의 블루레이로 나눌 수 있는지 확인하는 함수
bool canDivide(const vector<int>& lessons, int M, int maxSize) {
    int currentSum = 0; // 현재 블루레이에 들어 있는 총 강의 시간
    int count = 1;      // 사용된 블루레이 수

    for (int length : lessons) {
        // 현재 블루레이에 강의를 추가할 수 없으면 새로운 블루레이를 사용해야 함
        if (currentSum + length > maxSize) {
            count++;
            currentSum = length; // 새 블루레이에 현재 강의부터 시작
            if (count > M) { // 사용된 블루레이 수가 M을 초과하면 불가능
                return false;
            }
        }
        else {
            currentSum += length; // 현재 블루레이에 강의 추가
        }
    }
    return true;
}

int main() {
    fastio();

    int N, M; // N: 강의 수, M: 블루레이 수
    cin >> N >> M;

    vector<int> lessons(N);
    int totalSum = 0; // 모든 강의 시간의 총합
    int maxLength = 0; // 가장 긴 강의 시간

    // 강의 시간 입력 및 초기화
    for (int i = 0; i < N; i++) {
        cin >> lessons[i];
        totalSum += lessons[i];
        if (lessons[i] > maxLength) {
            maxLength = lessons[i]; // 가장 긴 강의 시간 찾기
        }
    }

    // 이분 탐색을 위한 초기 범위 설정
    int low = maxLength;  // 가능한 블루레이 크기의 최솟값
    int high = totalSum;  // 가능한 블루레이 크기의 최댓값
    int result = high;    // 블루레이의 최소 크기 초기화

    while (low <= high) {
        int mid = (low + high) / 2; // 현재 블루레이 크기

        // mid 크기의 블루레이로 강의를 M개로 나눌 수 있는지 확인
        if (canDivide(lessons, M, mid)) {
            result = mid;  // 가능한 블루레이 크기 업데이트
            high = mid - 1; // 더 작은 크기도 가능한지 확인
        }
        else {
            low = mid + 1; // 더 큰 크기로 설정
        }
    }

    cout << result << endl; // 결과 출력

    return 0;
}