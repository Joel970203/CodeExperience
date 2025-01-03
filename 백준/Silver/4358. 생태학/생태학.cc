#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip> // for std::setprecision

using namespace std;

int main() {
    string treeName;
    map<string, int> treeCount; 
    int totalTrees = 0; 

    while (getline(cin, treeName)) {
        // 입력이 정상적으로 이루어졌을 경우
        if (!treeName.empty()) {
            treeCount[treeName]++; // 종의 개수를 증가시킴
            totalTrees++; // 전체 나무 수 증가
        }
    }

    // 출력
    for (const auto& entry : treeCount) {
        // 각 종의 비율 계산
        double percentage = (static_cast<double>(entry.second) / totalTrees) * 100;
        cout << entry.first << " " << fixed << setprecision(4) << percentage << endl;
    }

    return 0;
}