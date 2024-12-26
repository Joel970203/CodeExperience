#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> preset = {"aya", "ye", "woo", "ma"};
    
    for(int i = 0; i < babbling.size(); i++) {
        string str = babbling[i];
        string last_sound = ""; 
        
        bool is_valid = true;  
        
        while (!str.empty()) {
            bool found = false;
            
            // 각 발음에 대해 확인
            for (const string& sound : preset) {
                if (str.find(sound) == 0 && sound != last_sound) { 
                    str.erase(0, sound.size());
                    last_sound = sound;  
                    found = true;
                    break;  
                }
            }
            
            if (!found) {
                is_valid = false;
                break;
            }
        }
        
        if (is_valid && str.empty()) {
            answer++;
        }
    }
    
    return answer;
}
