#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> maxTree, minTree;
int treeHeight, treeSize, startLeaf;

void buildTree() 
{
    for (int i = startLeaf - 1; i > 0; i--)
    {
        maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
        minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
    }
}

int maxQuery(int start, int end) 
{
    int maxVal = -1e9;
    start += startLeaf;
    end += startLeaf;

    while (start <= end) 
    {
        if (start % 2 == 1) maxVal = max(maxVal, maxTree[start++]);
        if (end % 2 == 0) maxVal = max(maxVal, maxTree[end--]);
        start /= 2;
        end /= 2;
    }
    return maxVal;
}

int minQuery(int start, int end)
{
    int minVal = 1e9;
    start += startLeaf;
    end += startLeaf;

    while (start <= end) 
    {
        if (start % 2 == 1) minVal = min(minVal, minTree[start++]);
        if (end % 2 == 0) minVal = min(minVal, minTree[end--]);
        start /= 2;
        end /= 2;
    }
    return minVal;
}

int main() 
{
    fastio(); 

    int N, M;
    cin >> N >> M;

    treeHeight = ceil(log2(N));
    treeSize = (1 << (treeHeight + 1));
    startLeaf = treeSize / 2;

    maxTree.resize(treeSize);
    minTree.resize(treeSize);

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;
        maxTree[startLeaf + i] = num;
        minTree[startLeaf + i] = num;
    }

    buildTree();

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << minQuery(a - 1, b - 1) << " " << maxQuery(a - 1, b - 1) << "\n";
    }

    return 0;
}
