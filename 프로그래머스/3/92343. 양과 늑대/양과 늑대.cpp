#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_sheep = 0;
vector<vector<int>> graph;

void dfs(int sheep, int wolf, int curr, vector<int> &info, vector<int> next) {
    if (info[curr] == 0) sheep++;
    else wolf++;

    // 종료 조건: 양 <= 늑대
    if (wolf >= sheep) return;

    // 최대 양 갱신
    max_sheep = max(max_sheep, sheep);

    // 현재 노드의 자식 노드들을 탐색 후보로 추가
    for (int child : graph[curr]) {
        next.push_back(child);
    }

    // 다음으로 갈 수 있는 노드들에 대해 순회
    for (int i = 0; i < next.size(); i++) {
        int next_node = next[i];
        
        // 현재 next 리스트에서 i 번째 노드만 제거하고 넘겨줌
        vector<int> new_next = next;
        new_next.erase(new_next.begin() + i);
        
        dfs(sheep, wolf, next_node, info, new_next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    graph = vector<vector<int>>(info.size());

    for (auto &e : edges) {
        graph[e[0]].push_back(e[1]);
    }

    dfs(0, 0, 0, info, {});  // 루트에서 시작
    return max_sheep;
}
