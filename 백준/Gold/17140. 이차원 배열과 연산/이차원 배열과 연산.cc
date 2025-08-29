#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int r, c, k; cin >> r >> c >> k;
    r--; c--; // 0-index
    vector<vector<int>> graph(3, vector<int>(3));
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin >> graph[i][j];

    for (int cnt=0; cnt<=100; cnt++) {
        if (r < graph.size() && c < graph[0].size() && graph[r][c] == k) {
            cout << cnt << "\n";
            return 0;
        }

        int N = graph.size();
        int M = graph[0].size();

        if (N >= M) { // R 연산
            int newM = 0;
            vector<vector<int>> newGraph(N);
            for (int i=0; i<N; i++) {
                unordered_map<int,int> mp;
                for (int j=0; j<M; j++) {
                    if (graph[i][j] == 0) continue;
                    mp[graph[i][j]]++;
                }
                vector<pair<int,int>> temp(mp.begin(), mp.end());
                sort(temp.begin(), temp.end(), compare);

                vector<int> row;
                for (auto &p : temp) {
                    row.push_back(p.first);
                    row.push_back(p.second);
                }
                if (row.size() > 100) row.resize(100);
                newM = max(newM, (int)row.size());
                newGraph[i] = row;
            }
            for (int i=0; i<N; i++) newGraph[i].resize(newM, 0);
            graph = newGraph;
        } else { // C 연산 (열 기준)
            int newN = 0;
            vector<vector<int>> newGraph;
            // 열을 행처럼 뒤집어서 처리
            for (int j=0; j<M; j++) {
                unordered_map<int,int> mp;
                for (int i=0; i<N; i++) {
                    if (graph[i][j] == 0) continue;
                    mp[graph[i][j]]++;
                }
                vector<pair<int,int>> temp(mp.begin(), mp.end());
                sort(temp.begin(), temp.end(), compare);

                vector<int> col;
                for (auto &p : temp) {
                    col.push_back(p.first);
                    col.push_back(p.second);
                }
                if (col.size() > 100) col.resize(100);
                newN = max(newN, (int)col.size());
                newGraph.push_back(col);
            }
            // newGraph는 열단위 → 전치해서 다시 넣기
            vector<vector<int>> trans(newN, vector<int>(M, 0));
            for (int j=0; j<M; j++) {
                for (int i=0; i<newGraph[j].size(); i++) {
                    trans[i][j] = newGraph[j][i];
                }
            }
            graph = trans;
        }
    }

    cout << -1 << "\n";
}
