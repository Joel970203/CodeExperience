#include <iostream>
#include <vector>

using namespace std;

int inputResults[6][3];   // 입력으로 주어지는 각 국가의 결과 (승, 무, 패)
int outputResults[4];     // 각 테스트 케이스에 대한 출력 결과
int currentResults[6][3]; // 현재 시뮬레이션 중의 결과
vector<pair<int, int>> matchPairs; // 가능한 경기 조합 (15개)
bool isPossible;          // 결과가 가능한지 여부

// 백트래킹 함수
void backtrack(int matchIndex)
{
    if (matchIndex == 15) {
        for (int team = 0; team < 6; team++) {
            for (int resultType = 0; resultType < 3; resultType++) {
                if (inputResults[team][resultType] != currentResults[team][resultType]) {
                    return; // 결과가 일치하지 않으면 종료
                }
            }
        }
        isPossible = true; // 모든 결과가 일치하면 가능 표시
        return;
    }

    int teamA = matchPairs[matchIndex].first;  // 현재 매치의 첫 번째 팀
    int teamB = matchPairs[matchIndex].second; // 현재 매치의 두 번째 팀

    // 팀 A 승리, 팀 B 패배
    currentResults[teamA][0]++;
    currentResults[teamB][2]++;
    backtrack(matchIndex + 1);
    currentResults[teamA][0]--;
    currentResults[teamB][2]--;

    // 무승부
    currentResults[teamA][1]++;
    currentResults[teamB][1]++;
    backtrack(matchIndex + 1);
    currentResults[teamA][1]--;
    currentResults[teamB][1]--;

    // 팀 A 패배, 팀 B 승리
    currentResults[teamA][2]++;
    currentResults[teamB][0]++;
    backtrack(matchIndex + 1);
    currentResults[teamA][2]--;
    currentResults[teamB][0]--;
}

int main()
{
    // 가능한 모든 경기 조합 생성 (총 15경기)
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            matchPairs.push_back({ i, j });
        }
    }

    for (int testCase = 0; testCase < 4; testCase++) {
        for (int team = 0; team < 6; team++) {
            for (int resultType = 0; resultType < 3; resultType++) {
                cin >> inputResults[team][resultType];
            }
        }

        isPossible = false; 
        backtrack(0);      

        if (isPossible) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }

    return 0;
}
