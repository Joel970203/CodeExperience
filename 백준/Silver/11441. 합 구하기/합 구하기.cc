#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    int sum = 0;
    vector<int> v(N + 1, 0); // 누적합을 저장할 벡터, 크기는 N+1

    // 누적합 계산
    for (int i = 1; i <= N; i++) {
        int num; cin >> num;
        sum += num;
        v[i] = sum;  // v[i]에는 1부터 i까지의 누적합을 저장
    }

    int M; cin >> M;
    
    // M번 구간 합을 계산하여 출력
    while (M--) {
        int a, b; cin >> a >> b;
        cout << v[b] - v[a - 1] << "\n";  // 구간 [a, b]의 합은 v[b] - v[a-1]
    }

    return 0;
}
