#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) 
{
    int n = scores.size();
    int wanho_attitude = scores[0][0];
    int wanho_peer = scores[0][1];
    int wanho_sum = wanho_attitude + wanho_peer;

    // (태도 점수 내림차순, 같으면 동료평가 오름차순)
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });

    int max_peer = 0;
    bool wanho_eliminated = false;
    vector<pair<int,int>> valid; // 살아남은 사람들 (태도+동료, 인덱스는 안필요)

    for (int i = 0; i < n; i++)
    {
        int attitude = scores[i][0];
        int peer = scores[i][1];

        if (peer < max_peer)
        {
            // 탈락자
            if (attitude == wanho_attitude && peer == wanho_peer)
                wanho_eliminated = true;
        }
        else
        {
            // 살아남은 사람
            max_peer = max(max_peer, peer);
            valid.push_back({attitude + peer, i});
        }
    }

    if (wanho_eliminated)
        return -1;

    // 살아남은 사람들 중에서, 완호보다 합이 큰 사람 수 세기
    int better_count = 0;
    int wanho_sum_score = wanho_attitude + wanho_peer;

    for (auto& p : valid)
    {
        if (p.first > wanho_sum_score)
            better_count++;
    }

    return better_count + 1;
}
