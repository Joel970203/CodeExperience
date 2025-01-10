#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 두 기어가 맞물릴 수 있는지 확인하는 함수
bool canMesh(const string& gear1, const string& gear2, int offset) {
    int len1 = gear1.size();
    int len2 = gear2.size();

    // gear2를 gear1에 offset만큼 이동시켰을 때 서로 겹칠 수 있는지 확인
    for (int i = 0; i < len2; i++) {
        if (i + offset >= len1) break; // gear2의 범위가 gear1을 넘어서면 그만둠
        if (gear1[i + offset] == '2' && gear2[i] == '2') {
            return false; // "이"가 겹치면 맞물릴 수 없음
        }
    }
    return true;
}

// 가장 짧은 가로 너비를 찾는 함수
int findMinimumWidth(const string& gear1, const string& gear2) {
    int len1 = gear1.size();
    int len2 = gear2.size();
    int minWidth = len1 + len2; // 초기값은 두 길이를 합친 것보다 큰 값

    // gear2를 gear1의 왼쪽에 맞추어볼 때
    for (int offset = 0; offset <= len1; offset++) {                          
        if (canMesh(gear1, gear2, offset)) {                                  
            minWidth = min(minWidth, max(len1, offset + len2));
        }
    }

    // gear2를 gear1의 오른쪽에 맞추어볼 때
    for (int offset = 0; offset <= len2; offset++) {
        if (canMesh(gear2, gear1, offset)) {
            minWidth = min(minWidth, max(len2, offset + len1));
        }
    }

    return minWidth;
}

int main() {
    string gear1, gear2;

    // 기어 입력받기
    cin >> gear1 >> gear2;

    // 가장 짧은 가로 너비 찾기
    int result = findMinimumWidth(gear1, gear2);

    // 결과 출력
    cout << result << endl;

    return 0;
}