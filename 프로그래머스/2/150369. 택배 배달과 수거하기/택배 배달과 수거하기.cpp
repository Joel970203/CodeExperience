#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliver=0, pick=0, cnt=0;
    
    for(int i=n-1; i>=0; i--){
        deliver -= deliveries[i]; 
        pick -= pickups[i];
        
        while(1){
            if(deliver >=0 && pick >=0)
                break;
            deliver += cap; 
            pick += cap; 
            cnt++; 
        }
        answer += (i+1)*2*cnt; 
        cnt=0;
    }
    return answer;
}