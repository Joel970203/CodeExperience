#include <iostream>
#include <vector>
using namespace std;

vector<int> buildings;
vector<vector<int>> levels;

void buildTree(int start, int end, int depth) 
{
    if (start > end) return;

    int mid = (start + end) / 2;  
    levels[depth].push_back(buildings[mid]);

    buildTree(start, mid - 1, depth + 1);

   
    buildTree(mid + 1, end, depth + 1);
}

int main() {
    int K;
    cin >> K;

    int nodeCount = (1 << K) - 1;  
    buildings.resize(nodeCount);
    levels.resize(K);

    for (int i = 0; i < nodeCount; i++) 
    {
        cin >> buildings[i];
    }

    buildTree(0, nodeCount - 1, 0);

    for (int i = 0; i < K; i++) 
    {
        for (int node : levels[i]) 
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
