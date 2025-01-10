#include <iostream>
#include <cmath>
using namespace std;

int galaxy(double x, double y) {
    double dis = y - x;

    if (dis == 1) {
        return 1;
    }

    if (dis == 2) {
        return 2;
    }

    int k = sqrt(dis); // 최대 속도 k는 거리의 제곱근과 비슷하게 나옴
    int cnt;

    if (dis == k * k) {
        cnt = 2 * k - 1;
    } else if (dis <= k * k + k) {
        cnt = 2 * k;
    } else {
        cnt = 2 * k + 1;
    }

    return cnt;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        double x, y;
        cin >> x >> y;
        cout << galaxy(x, y) << endl;
    }
}
