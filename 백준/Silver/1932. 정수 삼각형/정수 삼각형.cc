#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; i++) 
    {
        triangle[i].resize(i + 1); 
        for (int j = 0; j <= i; j++) 
        {
            cin >> triangle[i][j];
        }
    }


    for (int i = n - 2; i >= 0; i--) 
    {
        for (int j = 0; j <= i; j++) 
        {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }


    cout << triangle[0][0] << endl; 
    return 0;
}
