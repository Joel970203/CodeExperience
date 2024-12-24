#include <string>
#include <cctype> // for isalpha, isdigit, tolower
using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계: 모든 대문자를 소문자로 변환
    for (char &c : new_id) {
        c = tolower(c);
    }

    // 2단계: 알파벳 소문자, 숫자, -, _, . 제외한 모든 문자 제거
    for (char c : new_id) {
        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.') {
            answer += c;
        }
    }

    // 3단계: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    string temp = "";
    for (char c : answer) {
        if (!temp.empty() && temp.back() == '.' && c == '.') {
            continue;
        }
        temp += c;
    }
    answer = temp;

    // 4단계: 마침표(.)가 처음이나 끝에 위치한다면 제거
    if (!answer.empty() && answer.front() == '.') {
        answer.erase(answer.begin());
    }
    if (!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }

    // 5단계: 빈 문자열이라면 "a"를 대입
    if (answer.empty()) {
        answer = "a";
    }

    // 6단계: 길이가 16자 이상이면, 첫 15개의 문자만 남기고 제거
    //        제거 후 마침표(.)가 끝에 위치한다면 마침표(.) 제거
    if (answer.length() > 15) {
        answer = answer.substr(0, 15);
        if (answer.back() == '.') {
            answer.pop_back();
        }
    }

    // 7단계: 길이가 2자 이하라면, 마지막 문자를 길이가 3이 될 때까지 반복
    while (answer.length() < 3) {
        answer += answer.back();
    }

    return answer;
}
