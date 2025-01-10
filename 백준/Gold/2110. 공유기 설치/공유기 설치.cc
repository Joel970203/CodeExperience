#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canInstallRouters(const vector<int>& houses, int distance, int C) {
    int count = 1; // 첫 번째 집에 설치
    int lastInstalled = houses[0]; // 마지막으로 설치된 공유기의 위치

    for (int i = 1; i < houses.size(); i++) {
        if (houses[i] - lastInstalled >= distance) {
            count++;
            lastInstalled = houses[i];
        }
    }

    return count >= C;
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int left = 1; // 최소 거리
    int right = houses[N - 1] - houses[0]; // 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canInstallRouters(houses, mid, C)) {
            answer = mid; // 이 거리로 설치할 수 있으므로, 결과를 저장
            left = mid + 1; // 더 큰 거리를 시도
        }
        else {
            right = mid - 1; // 거리를 줄여서 시도
        }
    }

    cout << answer << endl;

    return 0;
}