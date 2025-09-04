#include <iostream>
#include <vector>
#include <cmath>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

static vector<long long> tree;

void setTree() {
    for (int i = tree.size() / 2 - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];  // 부모 노드 = 왼쪽 자식 + 오른쪽 자식
    }
}

void changeVal(int index, long long val)
{
	long long diff = val - tree[index];  // 변경 차이
	tree[index] = val;  // 리프 노드 값 변경

	while (index > 1) {
		index /= 2;
		tree[index] = tree[index * 2] + tree[index * 2 + 1];  // 부모 노드 갱신
	}
}

long long getSum(int start, int end)
{
	long long sum = 0;
	while (start <= end)
	{
		if (start % 2 == 1) sum += tree[start++];  // 오른쪽 노드 포함 후 이동
		if (end % 2 == 0) sum += tree[end--];      // 왼쪽 노드 포함 후 이동

		start /= 2;
		end /= 2;
	}
	return sum;
}

int main()
{
	fastio();

	int N, M, K;
	cin >> N >> M >> K;

	int treeHeight = ceil(log2(N));  // 트리 높이
	int treeSize = (1 << (treeHeight + 1));  // 2^(h+1) 크기 설정
	int leftNodeStartIdx = treeSize / 2;  // 리프 노드 시작 인덱스

	tree.resize(treeSize);

	for (int i = leftNodeStartIdx; i < leftNodeStartIdx + N; i++)
	{
		cin >> tree[i];
	}

	setTree();  // 세그먼트 트리 초기화

	for (int i = 0; i < M + K; i++)
	{
		int a;
		long long b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			changeVal(leftNodeStartIdx + b - 1, c);
		}
		else if (a == 2)
		{
			cout << getSum(leftNodeStartIdx + b - 1, leftNodeStartIdx + c - 1) << '\n';
		}
	}
}
