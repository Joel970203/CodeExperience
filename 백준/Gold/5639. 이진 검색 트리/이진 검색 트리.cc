#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;  
int idx = 0; 

void postorder(int start, int end) 
{
    if (start > end) return;

    int root = preorder[start]; 
    int split = start + 1; 

    while (split <= end && preorder[split] < root) 
    {
        split++;
    }

    postorder(start + 1, split - 1); 
    postorder(split, end);  

    cout << root << endl;
}

int main() {
    int n;

    while (cin >> n) 
    {
        preorder.push_back(n);
    }

    postorder(0, preorder.size() - 1);

    return 0;
}
