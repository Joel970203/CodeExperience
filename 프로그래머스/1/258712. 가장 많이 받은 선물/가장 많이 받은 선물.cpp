#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    // 친구 이름을 인덱스로 매핑
    map<string, int> names;
    for (int i = 0; i < friends.size(); i++) {
        names[friends[i]] = i;
    }

    int n = friends.size();
    // 주고받은 선물 기록 저장
    vector<vector<int>> gift_Memo(n, vector<int>(n, 0));
    for (const auto& gift : gifts) {
        size_t space = gift.find(' ');
        string sender = gift.substr(0, space);
        string receiver = gift.substr(space + 1);
        gift_Memo[names[sender]][names[receiver]]++;
    }

    // 선물 지수 계산
    vector<int> scores(n, 0);
    for (int i = 0; i < n; i++) {
        int sent = 0, received = 0;
        for (int j = 0; j < n; j++) {
            sent += gift_Memo[i][j];
            received += gift_Memo[j][i];
        }
        scores[i] = sent - received; // 선물 지수 계산
    }

    // 다음 달 선물 받을 횟수 계산
    vector<int> next_gifts(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // 자신 제외

            if (gift_Memo[i][j] > gift_Memo[j][i]) {
                // i가 j에게 더 많이 선물을 줬다면 j가 i에게 선물 받음
                next_gifts[i]++;
            }
            else if (gift_Memo[i][j] == gift_Memo[j][i]) {
                // 주고받은 선물이 같다면
                if (scores[i] > scores[j]) {
                    // 선물 지수가 높은 사람이 선물 받음
                    next_gifts[i]++;
                }
            }
        }
    }

    // 가장 많이 선물을 받는 친구의 선물 개수 반환
    return *max_element(next_gifts.begin(), next_gifts.end());
}