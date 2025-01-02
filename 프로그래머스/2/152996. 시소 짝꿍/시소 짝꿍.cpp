#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<long long, long long> weightCount;

    for (int weight : weights) {
        weightCount[weight]++;
    }

    for (const auto& entry : weightCount) {
        long long w = entry.first;
        long long count = entry.second;

        // 1. w * 3 == 짝 => w * 3 / 2 존재하는지 확인
        if (weightCount.count(w * 3 / 2) && (w * 3) % 2 == 0) {
            answer += count * weightCount[w * 3 / 2];
        }
        // 2. w * 4 == 짝 => w * 4 / 3 존재하는지 확인
        if (weightCount.count(w * 4 / 3) && (w * 4) % 3 == 0) {
            answer += count * weightCount[w * 4 / 3];
        }
        // 3. w * 2 == 짝 => w * 2 존재하는지 확인
        if (weightCount.count(w * 2)) {
            answer += count * weightCount[w * 2];
        }
        // 4. 자기 자신과 짝 => 동일한 무게의 쌍은 무조건 존재
        if (weightCount.count(w)) {
            answer += (count * (count - 1)) / 2; // 동일한 무게끼리 짝을 이룰 때
        }
    }

    return answer;
}
