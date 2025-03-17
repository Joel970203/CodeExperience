#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void buildTree(vector<long long> &segmentTree,int startLeaf)
{
	for (int i = startLeaf - 1; i > 0; i--)
	{
		segmentTree[i] = (segmentTree[i * 2] * segmentTree[i * 2 + 1]) % 1000000007;
	}
}

void updateTree(vector<long long>& segmentTree,int startLeaf,int b,int c)
{
	int position = startLeaf + b - 1;
	segmentTree[position] = c;
 
	while (position > 1)
	{
		position /= 2;
		segmentTree[position] = (segmentTree[position * 2] * segmentTree[position * 2 + 1]) % 1000000007;
	}
}

long long Query(vector<long long>& segmentTree,int startLeaf, int b, int c)
{
	int ans = 1;
	int startPosition = startLeaf + b - 1;
	int endPosition = startLeaf + c - 1;

	while (startPosition <= endPosition)
	{
		if (startPosition % 2 == 1) 
		{
			ans = (ans * segmentTree[startPosition]) % 1000000007;
			startPosition++;
		}
		if (endPosition % 2 == 0) 
		{
			ans = (ans * segmentTree[endPosition]) % 1000000007;
			endPosition--;
		}

		startPosition /= 2;
		endPosition /= 2;
	}

	return ans;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int treeHeight = ceil(log2(N));
	int treeSize = 1 << treeHeight + 1;
	int startLeaf = treeSize / 2;

	vector<long long> segmentTree(treeSize);

	for (int i = 0; i < N; i++)
	{
		cin >> segmentTree[startLeaf + i];
	}

	buildTree(segmentTree, startLeaf);

	for (int i = 0; i < M+K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			updateTree(segmentTree, startLeaf, b, c);
		}

		else if (a == 2)
		{
			cout << Query(segmentTree, startLeaf, b, c) % 1000000007 << "\n";
		}
	}


}