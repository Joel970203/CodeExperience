#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int check = nums[i] + nums[j] + nums[k];
                bool isPrime = true;
                for (int q = 2; q * q <= check; q++) {
                    if (check % q == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) {
                    answer++;
                }
            }
        }
    }

    return answer;
}
