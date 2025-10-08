#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> db;

// info 한 줄을 받아서 모든 조합 key를 생성
void makeKeys(vector<string> &tokens, int score, int idx, string key) {
    if (idx == 4) {
        db[key].push_back(score);
        return;
    }

    // 현재 조건 포함
    makeKeys(tokens, score, idx + 1, key + tokens[idx]);
    // 현재 조건 대신 '-'
    makeKeys(tokens, score, idx + 1, key + "-");
}

vector<int> solution(vector<string> info, vector<string> query) {
    // 1️⃣ info 전처리
    for (string &s : info) {
        stringstream ss(s);
        vector<string> tokens(5);
        for (int i = 0; i < 5; i++) ss >> tokens[i];

        makeKeys(tokens, stoi(tokens[4]), 0, "");
    }

    // 2️⃣ 각 key별 점수 정렬
    for (auto &p : db) sort(p.second.begin(), p.second.end());

    vector<int> answer;

    // 3️⃣ 쿼리 처리
    for (string &q : query) {
        // 문자열 파싱: "and" 제거 후 5개 토큰 추출
        for (int i = 0; i < q.size(); i++)
            if (q[i] == 'a' && i + 2 < q.size() && q.substr(i, 3) == "and")
                q[i] = ' ', q[i+1] = ' ', q[i+2] = ' ';

        stringstream ss(q);
        vector<string> cond(5);
        for (int i = 0; i < 5; i++) ss >> cond[i];

        string key = cond[0] + cond[1] + cond[2] + cond[3];
        int score = stoi(cond[4]);

        // 해당 key의 점수 목록에서 score 이상인 사람 수 구하기
        if (db.find(key) == db.end()) {
            answer.push_back(0);
            continue;
        }

        auto &v = db[key];
        int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
        answer.push_back(v.size() - idx);
    }

    return answer;
}
