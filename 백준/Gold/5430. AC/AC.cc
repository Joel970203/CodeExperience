#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string p;
        int n;
        cin >> p;
        cin >> n;

        string temp;
        cin >> temp;

        deque<int> arr;
        string num = "";

        // 배열 파싱
        for (char c : temp) 
        {
            if (isdigit(c)) 
            {
                num += c;
            }
            else if (!num.empty()) 
            {
                arr.push_back(stoi(num));
                num = "";
            }
        }

        bool isReversed = false;  // 뒤집기 플래그
        bool isError = false;

        for (char cmd : p) 
        {
            if (cmd == 'R') 
            {
                isReversed = !isReversed;  // 뒤집기 플래그 토글
            }
            else if (cmd == 'D')
            {
                if (arr.empty()) 
                {
                    isError = true;
                    break;
                }
                if (isReversed)
                {
                    arr.pop_back();  // 뒤집힌 상태에서는 뒤에서 삭제
                }
                else {
                    arr.pop_front();  // 일반 상태에서는 앞에서 삭제
                }
            }
        }

        // 결과 출력
        if (isError) 
        {
            cout << "error" << endl;
        }
        else 
        {
            cout << "[";
            if (isReversed) 
            {
                for (auto it = arr.rbegin(); it != arr.rend(); ++it)
                {
                    cout << *it;
                    if (it + 1 != arr.rend()) cout << ",";
                }
            }
            else
            {
                for (auto it = arr.begin(); it != arr.end(); ++it)
                {
                    cout << *it;
                    if (it + 1 != arr.end()) cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }
}
