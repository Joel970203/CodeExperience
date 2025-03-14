#include <iostream>
#include <vector>
using namespace std;

int G, P;
vector<int> parent;

int find(int x) 
{
    if (parent[x] == x) return x; 
    return parent[x] = find(parent[x]); 
}

void unionGate(int a, int b) 
{
    parent[a] = b; 
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> G >> P;

    parent.resize(G + 1);

    for (int i = 1; i <= G; i++)
    {
        parent[i] = i;
    }

    int count = 0; 

    for (int i = 0; i < P; i++) 
    {
        int gi;
        cin >> gi;

        int dockingGate = find(gi);

        if (dockingGate == 0) break;

        unionGate(dockingGate, dockingGate - 1);

        count++;
    }

    cout << count << "\n";

    return 0;
}
