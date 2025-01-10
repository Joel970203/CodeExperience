#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int x, n, v;
    cin >> n >> x;
    vector<int> visitor(n);

    for (int i = 0; i < n; ++i) {
        cin >> visitor[i];
    }

    int v_max = 0, total = 0;
    unordered_map<int, int> count;

    // 처음 x개의 합을 구함
    for (int i = 0; i < x; ++i) {
        total += visitor[i];
    }

    v_max = total;
    count[v_max]++;

    // 슬라이딩 윈도우로 다음 부분 합들을 구함
    for (int i = x; i < n; ++i) {
        total += visitor[i] - visitor[i - x]; // 새로 더하고 오래된 값 빼기
        v_max = max(v_max, total);
        count[total]++;
    }

    if (v_max == 0) {
        cout << "SAD" << endl;
    }
    else {
        cout << v_max << endl;
        cout << count[v_max] << endl; // v_max의 빈도를 출력
    }

    return 0;
}