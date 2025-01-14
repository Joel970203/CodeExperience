#include <string>
#include <vector>
using namespace std;

bool isWinning(const vector<string>& board, char player)
{
    for (int i = 0; i < 3; ++i) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

int solution(vector<string> board) 
{
    int cnt_o = 0, cnt_x = 0;

    for (const string& row : board) 
    {
        for (char cell : row) {
            if (cell == 'O') cnt_o++;
            if (cell == 'X') cnt_x++;
        }
    }

    if (cnt_x > cnt_o || cnt_o > cnt_x + 1) return 0;

    bool O_wins = isWinning(board, 'O');
    bool X_wins = isWinning(board, 'X');

    if (O_wins && X_wins) return 0; 
    if (O_wins && cnt_o != cnt_x + 1) return 0; 
    if (X_wins && cnt_o != cnt_x) return 0;     

    return 1; 
}
