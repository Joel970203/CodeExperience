#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sdocu(9, vector<int>(9));

bool isValid(int x, int y, int num) 
{
    // 같은 행 
    for (int i = 0; i < 9; i++) 
    {
        if (sdocu[y][i] == num) return false;
    }
    // 같은 열
    for (int i = 0; i < 9; i++) 
    {
        if (sdocu[i][x] == num) return false;
    }
    // 3x3 박스 확인
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (sdocu[startY + i][startX + j] == num) return false;
        }
    }
    return true;
}

// 백트래킹 함수
bool solve() {
    for (int y = 0; y < 9; y++) 
    {
        for (int x = 0; x < 9; x++) 
        {
            if (sdocu[y][x] == 0) 
            { 
                for (int num = 1; num <= 9; num++) 
                { 
                    if (isValid(x, y, num)) 
                    {
                        sdocu[y][x] = num; 
                        if (solve()) return true; 
                        sdocu[y][x] = 0; // 백트래킹 
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> sdocu[i][j];
        }
    }

    if (solve()) 
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                cout << sdocu[i][j] << " ";
            }
            cout << endl;
        }
    }

    else 
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}
