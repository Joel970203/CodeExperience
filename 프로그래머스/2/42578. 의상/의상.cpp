#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;  // 초기값을 1로 설정
    
    unordered_map<string, int> comb;
    
    for(int i = 0; i < clothes.size(); i++) {
        comb[clothes[i][1]]++;  // 옷 종류별로 개수를 셈
    }
    
    for(auto &iter : comb) {
        answer *= (iter.second + 1);  // 각 종류의 의상 개수 + 1을 곱함 (해당 의상을 착용하지 않는 경우 포함)
    }
    
    return answer - 1;  // 모든 옷을 착용하지 않는 경우(0가지)를 제외
}
