#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) 
{
    int row = relation.size(); //행 
    int col = relation[0].size(); //열 
    vector<int> candidateKeys; // 후보키로 선정된 컬럼 조합의 비트마스크를 저장

    // 모든 컬럼 조합을 검사
    for (int mask = 1; mask < (1 << col); mask++) 
    {
        set<string> tuples;
        // 각 튜플에 대해 선택한 컬럼의 값들을 연결하여 하나의 문자열로 만듦
        for (int i = 0; i < row; i++)
        {
            string key = "";
            for (int j = 0; j < col; j++)
            {
                if (mask & (1 << j)) {
                    key += relation[i][j] + "|"; // 구분자를 사용하여 값들을 구분
                }
            }
            tuples.insert(key);
        }
        // 유일성을 만족하지 않는다면 다음 조합으로 넘어감
        if (tuples.size() != row) continue;

        // 최소성 검사: 기존 후보키의 부분집합인지 확인
        bool minimal = true;
        for (int candidate : candidateKeys) 
        {
            // 이미 후보키로 선택된 조합(candidate)이 현재 조합(mask)의 부분집합이면 minimal 조건 위배
            if ((candidate & mask) == candidate)
            {
                minimal = false;
                break;
            }
        }
        if (minimal) 
        {
            candidateKeys.push_back(mask);
        }
    }
    return candidateKeys.size();
}

