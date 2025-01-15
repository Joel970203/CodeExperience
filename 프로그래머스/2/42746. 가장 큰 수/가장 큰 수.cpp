#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 비교 함수
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> numStrings;

   
    for (int num : numbers) {
        numStrings.push_back(to_string(num));
    }


    sort(numStrings.begin(), numStrings.end(), compare);


    string result;
    for (string num : numStrings) {
        result += num;
    }

    if (result[0] == '0') {
        return "0";
    }

    return result;
}

int main() {
    vector<int> numbers = { 6, 10, 2 };
    cout << solution(numbers) << endl; 

    numbers = { 3, 30, 34, 5, 9 };
    cout << solution(numbers) << endl; 

    return 0;
}