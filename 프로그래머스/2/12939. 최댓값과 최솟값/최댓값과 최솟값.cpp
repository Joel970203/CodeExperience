#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> array;

    // 문자열에서 공백으로 구분된 숫자 추출
    stringstream ss(s);
    string temp;
    while (ss >> temp) {
        array.push_back(stoi(temp)); // 문자열을 정수로 변환
    }

    // 정렬
    sort(array.begin(), array.end());

    // 최소값과 최대값 추가
    answer += to_string(array.front()); // 최소값
    answer += " ";
    answer += to_string(array.back());  // 최대값

    return answer;
}
