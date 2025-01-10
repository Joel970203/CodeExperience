#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// 이분탐색을 직접 구현한 함수
bool binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return true; // target을 찾으면 true 반환
        }
        else if (arr[mid] < target) {
            low = mid + 1; // target이 mid보다 크면 오른쪽 절반 탐색
        }
        else {
            high = mid - 1; // target이 mid보다 작으면 왼쪽 절반 탐색
        }
    }

    return false; // target을 찾지 못하면 false 반환
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); // 배열 A를 정렬

    int M;
    cin >> M;

    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < M; ++i) {
        // 배열 B의 원소가 배열 A에 존재하는지 직접 구현한 이분탐색을 사용하여 확인
        if (binarySearch(A, B[i])) {
            cout << "1\n"; // 존재하면 1
        }
        else {
            cout << "0\n"; // 존재하지 않으면 0
        }
    }

    return 0;
}