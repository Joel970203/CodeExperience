#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 원래 순서를 저장하기 위한 맵
unordered_map<int, int> order;

// 정렬 기준 함수
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return order[a.first] < order[b.first]; // 기존의 순서 지키기
    }
    return a.second > b.second; // 빈도 기준 내림차순 정렬
}

int main() {
    unordered_map<int, int> ans; // 숫자 빈도 저장

    int N, C;
    cin >> N >> C;

    // 수열 입력받기 및 빈도 계산
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ans[a]++;

        // 처음 등장할 때 인덱스 저장
        if (order[a] == 0) {
            order[a] = i + 1; // 1-based index
        }
    }

    // 빈도와 숫자를 담을 벡터 생성
    vector<pair<int, int>> vec(ans.begin(), ans.end());

    // 정렬
    sort(vec.begin(), vec.end(), cmp);

    // 결과 출력
    for (const auto& x : vec) {
        for (int i = 0; i < x.second; i++) {
            cout << x.first << " "; // 빈도만큼 출력
        }
    }

    return 0;
}