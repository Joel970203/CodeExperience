#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[100001];
int depth[100001];
int soldiers[100001]; 

int find(int x) 
{
    if (x == root[x]) {
        return x;
    }
    return root[x] = find(root[x]);
}

void Union(int x, int y) {
    int parent_x = find(x);
    int parent_y = find(y);

    if (parent_x == parent_y) {
        return;
    }

    if (depth[parent_x] < depth[parent_y]) {
        root[parent_x] = parent_y;
        soldiers[parent_y] += soldiers[parent_x]; 
        soldiers[parent_x] = 0; // 병력 초기화
    }
    else 
    {
        root[parent_y] = parent_x;
        soldiers[parent_x] += soldiers[parent_y];
        soldiers[parent_y] = 0;
    }

    if (depth[parent_x] == depth[parent_y])
    {
        depth[parent_x]++;
    }
}

void War(int x, int y) 
{
    int parent_x = find(x);
    int parent_y = find(y);

    if (parent_x == parent_y) 
    {
        return; // 이미 같은 집합이면 아무 일도 하지 않음
    }

    if (soldiers[parent_x] > soldiers[parent_y]) 
    {
        root[parent_y] = parent_x;
        soldiers[parent_x] -= soldiers[parent_y]; 
        soldiers[parent_y] = 0; 
    }
    else if (soldiers[parent_x] < soldiers[parent_y]) 
    {
        root[parent_x] = parent_y;
        soldiers[parent_y] -= soldiers[parent_x];
        soldiers[parent_x] = 0;
    }
    else 
    {
        soldiers[parent_x] = 0;
        soldiers[parent_y] = 0;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 초기화
    for (int i = 1; i <= N; i++) {
        root[i] = i;
        depth[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        cin >> soldiers[i];
    }

    // 기록 처리
    for (int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1) {
            Union(a, b); // 동맹
        }
        else if (op == 2) {
            War(a, b); // 전쟁
        }
    }

    vector<int> remainingSoldiers;
    for (int i = 1; i <= N; i++) {
        if (find(i) == i && soldiers[i] > 0) 
        { 
            remainingSoldiers.push_back(soldiers[i]);
        }
    }

    cout << remainingSoldiers.size() << '\n';
    sort(remainingSoldiers.begin(), remainingSoldiers.end());
    for (int soldier : remainingSoldiers) 
    {
        cout << soldier << ' ';
    }
    cout << '\n';

    return 0;
}
