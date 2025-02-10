#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board(9, vector<int>(9));

bool isValid(int row, int col, int num) 
{
    for (int i = 0; i < 9; i++) 
    {
        if (board[row][i] == num || board[i][col] == num) return false;
    }

    int boxRowStart = row / 3 * 3;
    int boxColStart = col / 3 * 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[boxRowStart + i][boxColStart + j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku() 
{
    for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++) 
        {
            if (board[row][col] == 0)
            { 
                for (int num = 1; num <= 9; num++)  // 사전 순 보장 
                {
                    if (isValid(row, col, num)) 
                    {
                        board[row][col] = num;
                        if (solveSudoku()) return true;
                        board[row][col] = 0; // 백트래킹
                    }
                }
                return false; // 모든 숫자가 유효하지 않으면 실패
            }
        }
    }
    return true; // 모든 칸이 채워졌다면 성공
}

int main()
{
    // 입력 받기 (각 줄을 문자열로 읽어 숫자로 변환)
    for (int i = 0; i < 9; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = line[j] - '0'; // 문자 -> 숫자로 변환
        }
    }

    // 스도쿠 풀이 실행
    if (solveSudoku())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}