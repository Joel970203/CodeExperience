#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(1)
    {
        int bmax = max(bill[0],bill[1]); // 26
        int wmax = max(wallet[0],wallet[1]); // 30 
        
        int bmin = min(bill[0],bill[1]); // 17
        int wmin = min(wallet[0],wallet[1]); // 15
        
        if(bmax > wmax || bmin > wmin)
        {
            if(bill[0] > bill[1])
            {
                bill[0] /= 2;
                answer++;
            }
            else
            {
                bill[1] /= 2;
                answer++;
            }
        }
        else
        {
            break;
        }
    }
    
    return answer;
}

