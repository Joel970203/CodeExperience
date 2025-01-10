#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N, M;
vector<vector<int>> arr(51, vector<int>(51, 0)); // 도시 지도
vector<pair<int, int>> houses; // 집 좌표
vector<pair<int, int>> chickens; // 치킨집 좌표
vector<int> combi; // 조합을 위한 벡터 (치킨집 선택 여부)

// 두 좌표 사이의 거리를 계산하는 함수
int calc_distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 선택된 M개의 치킨집들로 도시의 총 치킨 거리를 계산하는 함수
int calc_chicken_distance() {
    int total_dist = 0;

    // 모든 집에 대해 가장 가까운 치킨집 거리 계산
    for (auto& house : houses) {
        int min_dist = 1e9; // 충분히 큰 값으로 초기화
        for (int i = 0; i < chickens.size(); i++) {
            if (combi[i] == 1) { // 선택된 치킨집에 대해서만 거리 계산
                min_dist = min(min_dist, calc_distance(house, chickens[i]));
            }
        }
        total_dist += min_dist;
    }

    return total_dist;
}

int main() {
    fastio();

    cin >> N >> M;

    // 도시 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a;
            cin >> a;
            arr[i][j] = a;
            if (a == 1) {
                houses.push_back({ i, j }); // 집인 경우
            }
            else if (a == 2) {
                chickens.push_back({ i, j }); // 치킨집인 경우
            }
        }
    }

    // 조합을 위한 벡터 초기화 (M개를 고르는 것)
    combi.resize(chickens.size(), 0);
    for (int i = 0; i < M; i++) {
        combi[i] = 1;
    }

    int min_chicken_distance = 1e9; // 최소 치킨 거리

    // M개의 치킨집을 선택하는 조합을 구함
    do {
        // 선택된 M개의 치킨집에 대해 도시의 총 치킨 거리 계산
        int current_chicken_distance = calc_chicken_distance();
        min_chicken_distance = min(min_chicken_distance, current_chicken_distance);
    } while (prev_permutation(combi.begin(), combi.end()));

    // 최소 치킨 거리 출력
    cout << min_chicken_distance << '\n';

    return 0;
}