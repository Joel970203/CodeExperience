#include <string>
#include <vector>
#include <numeric> 
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    int n = queue1.size();
    int m = queue2.size();
    vector<int> all(queue1);
    all.insert(all.end(), queue2.begin(), queue2.end());
    
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long total = sum1 + sum2;
    if (total % 2 != 0) return -1; // 홀수면 불가능
    
    long long target = total / 2;
    int i = 0, j = n; // i: queue1 front, j: queue2 front
    int limit = 2 * (n + m);
    int cnt = 0;
    
    while (cnt <= limit) {
        if (sum1 == target) return cnt;
        
        if (sum1 > target) 
        { // queue1이 큼 → 하나 빼서 queue2에 넣기
            sum1 -= all[i % (n + m)];
            i++;
        } 
        else 
        { // queue2가 큼 → 하나 빼서 queue1에 넣기
            sum1 += all[j % (n + m)];
            j++;
        }
        cnt++;
    }
    
    return -1;
}
