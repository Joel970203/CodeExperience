#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int height = triangle.size();

    for (int i = height - 2; i >= 0; i--)
    { 
        for (int j = 0; j < triangle[i].size(); j++)
        {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    return triangle[0][0];
}
