#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

// 함수를 통해 |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 계산
int calculateDifference(const vector<int>& permutation) {
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += abs(permutation[i] - permutation[i + 1]);
    }
    return sum;
}

int main() {
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int maxDifference = 0;

    // 모든 순열을 생성
    sort(arr.begin(), arr.end()); // 순열 생성을 위해 정렬
    do {
        // 현재 순열에 대한 차이의 합 계산
        int currentDifference = calculateDifference(arr);
        maxDifference = max(maxDifference, currentDifference); // 최댓값 업데이트
    } while (next_permutation(arr.begin(), arr.end())); // 다음 순열로 이동

    cout << maxDifference << endl; // 결과 출력
    return 0;
}