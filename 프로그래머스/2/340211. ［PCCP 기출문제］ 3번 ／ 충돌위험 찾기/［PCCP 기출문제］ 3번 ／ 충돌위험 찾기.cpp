#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;

    // M[시간][(x,y)] = 해당 시각에 좌표 (x,y)에 도착한 로봇 개수
    map<int, map<pair<int, int>, int>> M;

    // 모든 로봇 경로 처리
    for(int i = 0; i < routes.size(); ++i)
    {
        // 시작 좌표 (routes[i][0]은 points의 1-based index)
        int StartPosX = points[routes[i][0] - 1][0];
        int StartPosY = points[routes[i][0] - 1][1];

        // 경과 시간(초) — 로봇별로 0초부터 시작
        int Second = 0;

        // 출발 시각(0초) 위치 기록
        M[Second][{StartPosX, StartPosY}] += 1;

        // 현재 경로의 다음 포인트들로 차례차례 이동
        for(int j = 1; j <= routes[i].size() - 1; ++j)
        {
            // 이번에 도착해야 할 목표 좌표
            int EndPosX = points[routes[i][j] - 1][0];
            int EndPosY = points[routes[i][j] - 1][1];

            // 목표 지점까지 1초 단위로 한 칸씩 이동
            while(true)
            {
                if(StartPosX == EndPosX) // X좌표가 같으면 Y축 이동
                {
                    if(StartPosY == EndPosY) // 목표에 도착
                    {
                        break; // 이번 구간 종료
                    }
                    else if(StartPosY < EndPosY) // 아래로 이동
                    {
                        StartPosY += 1;
                    }
                    else // 위로 이동
                    {
                        StartPosY -= 1;
                    }
                }
                else if(StartPosX < EndPosX) // 오른쪽으로 이동
                {
                    StartPosX += 1;
                }
                else // 왼쪽으로 이동
                {
                    StartPosX -= 1;
                }

                // 1초 경과시키고, 새 위치를 기록
                M[++Second][make_pair(StartPosX, StartPosY)] += 1;
            }
        }
    }

    // 모든 시간·좌표 기록을 순회
    for(const auto& X : M) // X.first: 시간, X.second: 해당 시각의 좌표 map
    {
        for(const auto& Y : X.second) // Y.first: (x,y), Y.second: 방문 로봇 수
        {
            // 같은 시각 같은 좌표에 2대 이상이 있으면 충돌 카운트
            if(Y.second >= 2)
            {
                answer += 1;
            }
        }
    }

    return answer;
}
