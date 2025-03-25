#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> nutrients(N, vector<int>(N, 5));
    vector<vector<deque<int>>> trees(N, vector<deque<int>>(N)); 

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < M; i++) 
    {
        int x, y, z;
        cin >> y >> x >> z; 
        trees[y - 1][x - 1].push_back(z);
    }

    for (int year = 0; year < K; year++) {
        vector<vector<deque<int>>> new_trees(N, vector<deque<int>>(N));
        vector<vector<int>> dead(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                sort(trees[i][j].begin(), trees[i][j].end()); 
                for (int k = 0; k < trees[i][j].size(); k++) 
                {
                    int age = trees[i][j][k];
                    if (nutrients[i][j] >= age) {
                        nutrients[i][j] -= age;
                        new_trees[i][j].push_back(age + 1);
                    }
                    else 
                    {
                        dead[i][j] += age / 2; 
                    }
                }
            }
        }
        trees = new_trees;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                nutrients[i][j] += dead[i][j];
         
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                for (int age : trees[i][j]) 
                {
                    if (age % 5 == 0) 
                    {
                        for (int d = 0; d < 8; d++) 
                        {
                            int ni = i + dy[d];
                            int nj = j + dx[d];
                            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                                trees[ni][nj].push_front(1);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                nutrients[i][j] += A[i][j];
    }

    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result += trees[i][j].size();

    cout << result << "\n";
    return 0;
}
