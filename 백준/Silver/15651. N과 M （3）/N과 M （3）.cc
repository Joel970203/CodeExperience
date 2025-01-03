#include <iostream>
#include <vector>

using namespace std;

vector<int> sequence;
int N, M;

void dfs(int depth)
{
    // 깊이가 M에 도달했을 때 수열 출력
    if (M == depth)
    {
        for (int i = 0; i < sequence.size(); i++)
        {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        sequence.push_back(i);  // 수열에 i 추가
        dfs(depth + 1);  // 재귀 호출
        sequence.pop_back();  // 수열에서 i 제거
    }
}

int main()
{
    cin >> N >> M;  // N과 M 입력
    dfs(0);  // 깊이 0부터 시작
    return 0;
}
