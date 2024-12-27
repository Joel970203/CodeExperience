#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> term;

    // `terms`에서 키와 값을 `term`에 저장
    for (int i = 0; i < terms.size(); i++) {
        string key = terms[i].substr(0, 1); // 첫 번째 문자를 키로 사용
        int value = atoi(terms[i].substr(2).c_str()); // 숫자 부분을 정수로 변환
        term[key] = value;
    }

    // 각 `privacies` 항목을 처리
    for (int i = 0; i < privacies.size(); i++) {
        string privacyType = privacies[i].substr(11, 1); // 약관 종류 추출
        int su = term[privacyType]; // 약관 종류에 해당하는 기간

        int ytemp = atoi(privacies[i].substr(0, 4).c_str()); // 연도
        int mtemp = atoi(privacies[i].substr(5, 2).c_str()) + su; // 월 + 유효기간
        int dtemp = atoi(privacies[i].substr(8, 2).c_str()) - 1; // 하루 감소

        if (dtemp == 0) {
            dtemp = 28;
            mtemp -= 1;
        }

        if (mtemp > 12) {
            ytemp += (mtemp - 1) / 12; // 연도 증가
            mtemp = (mtemp - 1) % 12 + 1; // 월을 조정
        }

        int year = atoi(today.substr(0, 4).c_str());
        int month = atoi(today.substr(5, 2).c_str());
        int day = atoi(today.substr(8, 2).c_str());

        // 유효기간 초과 여부 확인
        if (year < ytemp) continue; // 유효기간이 남아있음
        if (year == ytemp && month < mtemp) continue; // 같은 해, 유효기간 남음
        if (year == ytemp && month == mtemp && day <= dtemp) continue; // 같은 달, 유효기간 남음

        // 유효기간 초과
        answer.push_back(i + 1); // 1-based index
    }

    return answer;
}
