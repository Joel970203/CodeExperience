#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 비교 함수: 두 문자열을 붙였을 때 더 큰 수가 되도록 비교
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> numStrings;

    // 정수를 문자열로 변환하여 벡터에 저장
    for (int num : numbers) {
        numStrings.push_back(to_string(num));
    }

    // 사용자 정의 비교 함수를 사용하여 정렬
    sort(numStrings.begin(), numStrings.end(), compare);

    // 정렬된 문자열을 하나로 합침
    string result;
    for (string num : numStrings) {
        result += num;
    }

    // 숫자 '0'으로만 구성된 경우를 처리
    if (result[0] == '0') {
        return "0";
    }

    return result;
}

int main() {
    vector<int> numbers = { 6, 10, 2 };
    cout << solution(numbers) << endl; // 출력: "6210"

    numbers = { 3, 30, 34, 5, 9 };
    cout << solution(numbers) << endl; // 출력: "9534330"

    return 0;
}