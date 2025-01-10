#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;  // 수의 개수
vector<int> numbers;  // 숫자 배열
int op[4];  // 연산자의 개수: +, -, *, /
int maxResult = -1e9;  // 최댓값 초기화
int minResult = 1e9;   // 최솟값 초기화

// 현재까지 계산된 값과 사용할 연산자 위치를 매개변수로 백트래킹 함수 작성
void backtrack(int index, int current) {
    // 모든 연산자를 사용한 경우 (N-1개의 연산자를 다 사용했을 때)
    if (index == N) {
        maxResult = max(maxResult, current);
        minResult = min(minResult, current);
        return;
    }

    // 각 연산자를 하나씩 사용해보는 과정
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {  // 사용할 수 있는 연산자가 남아있다면
            op[i]--;  // 해당 연산자 사용
            if (i == 0) backtrack(index + 1, current + numbers[index]);  // +
            else if (i == 1) backtrack(index + 1, current - numbers[index]);  // -
            else if (i == 2) backtrack(index + 1, current * numbers[index]);  // *
            else if (i == 3) backtrack(index + 1, current / numbers[index]);  // /
            op[i]++;  // 연산자 복구 (다음 경우를 위해)
        }
    }
}

int main() {
    // 입력 받기
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];  // +, -, *, /의 개수 입력
    }

    // 백트래킹 시작 (첫 번째 수를 가지고 시작)
    backtrack(1, numbers[0]);

    // 결과 출력
    cout << maxResult << endl;
    cout << minResult << endl;

    return 0;
}