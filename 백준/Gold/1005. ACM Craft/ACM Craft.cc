#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> time(N+1);  // 건물의 건설 시간
        vector<int> indegree(N+1, 0);  // 진입 차수 (의존성)
        vector<vector<int>> graph(N+1);  // 그래프 (건설 순서)
        vector<int> dp(N+1, 0);  // 각 건물을 건설 완료하는데 걸리는 최소 시간

        // 건설 시간 입력
        for (int i = 1; i <= N; i++) {
            cin >> time[i];
        }

        // 건설 순서 입력 (간선 추가)
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            indegree[Y]++;
        }

        // 승리하기 위한 건물 번호 W
        int W;
        cin >> W;

        // 위상 정렬을 위한 큐
        queue<int> q;

        // 초기 상태에서 건설을 시작할 수 있는 건물들은 진입 차수가 0인 건물들
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i];  // 진입 차수가 0인 건물은 건설이 바로 가능하므로, 초기 시간은 건설 시간과 같다.
            }
        }

        // 위상 정렬을 통한 최소 시간 계산
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // curr 건물의 건설이 완료되면, 그 이후에 건설할 수 있는 건물들을 확인
            for (int next : graph[curr]) {
                // 해당 건물을 건설할 때 걸리는 최소 시간 업데이트
                dp[next] = max(dp[next], dp[curr] + time[next]);
                
                // 그 건물의 진입 차수를 하나 줄임
                indegree[next]--;
                
                // 진입 차수가 0이 되면 큐에 추가
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 결과 출력 (승리해야 하는 건물 W의 최소 건설 시간)
        cout << dp[W] << endl;
    }

    return 0;
}
