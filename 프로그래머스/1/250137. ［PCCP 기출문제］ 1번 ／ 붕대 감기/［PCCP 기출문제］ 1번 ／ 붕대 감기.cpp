#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {    
    /*
    t초 동안 붕대를 감고, 초당  x만큼의 체력을 회복한다.
    t초 완료하면 추가 y만큼 회복 더한다.
    
    
    */
    vector<int> temp = attacks.back();
    int gameTime = temp[0];
    
    int cast = bandage[0]; // cast 시간 동안 연속이면 보너스
    int heal = bandage[1];
    int bonus = bandage[2];
    int k = 0; // attacks 순회 할 숫자
    int row = 0; // 연속으로 성공하는지 카운팅 
    int curHealth = health;
    
    for(int i =0; i<gameTime; i++)
    {
        if(i+1 == attacks[k][0])
        {   // 공격 당했을떄
            curHealth -= attacks[k][1];
            if(curHealth <= 0)
            {
                return -1;
            }
            row = 0;
            k++;
        }
        
        else
        {
            // 공격당하지 않았을때
            curHealth += heal;
            if(curHealth > health)
                {
                    curHealth = health;
                }
            row++;
            if(row == cast)
            {
                curHealth += bonus;
                if(curHealth > health)
                {
                    curHealth = health;
                }
                row = 0;
            }
        }
    }
    return curHealth;
}