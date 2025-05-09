#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int fairCutCount = 0; // 공평하게 자를 수 있는 지점 개수
    unordered_set<int> leftToppings; // 왼쪽 조각의 토핑 종류
    unordered_map<int, int> rightToppingCount; // 오른쪽 조각의 토핑 개수

    // 초기: 모든 토핑은 오른쪽에 있음
    for (int t : topping) {
        rightToppingCount[t]++;
    }

    int n = topping.size();
    for (int i = 0; i < n - 1; ++i) {
        int currentTopping = topping[i];

        // 왼쪽 조각에 토핑 추가
        leftToppings.insert(currentTopping);

        // 오른쪽 조각에서 토핑 하나 제거
        if (--rightToppingCount[currentTopping] == 0) {
            rightToppingCount.erase(currentTopping); // 종류 개수 줄이기
        }

        // 양쪽 종류 수가 같으면 공평한 컷
        if (leftToppings.size() == rightToppingCount.size()) {
            fairCutCount++;
        }
    }

    return fairCutCount;
}
