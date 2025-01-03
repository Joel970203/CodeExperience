#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M;

    unordered_map<string, int> map;
    vector<string> list(N);

    // 행 입력 및 동일 상태의 빈도 계산
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        list[i] = line;
        map[line]++;
    }

    cin >> K;

    int max_rows = 0;

    // 각 행의 상태를 기준으로 가능한 최대 켜진 행 계산
    for (const auto& entry : map) {
        const string& row = entry.first;
        int row_count = entry.second;

        // 0의 개수 세기
        int zero_count = count(row.begin(), row.end(), '0');

        // 조건: 0의 개수 <= K && (K - zero_count) % 2 == 0
        if (zero_count <= K && (K - zero_count) % 2 == 0) {
            max_rows = max(max_rows, row_count);
        }
    }

    cout << max_rows << endl;
    return 0;
}