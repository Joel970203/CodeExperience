#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> nums(N);
    map<int, int> freq; 
    int sum = 0;

    for (int i = 0; i < N; ++i) 
    {
        cin >> nums[i];
        sum += nums[i];
        freq[nums[i]]++; 
    }

    sort(nums.begin(), nums.end());

    int maxFreq = 0;
    vector<int> modeCandidates;

    for (const auto& p : freq) 
    {
        if (p.second > maxFreq)
        {
            maxFreq = p.second;
            modeCandidates.clear();
            modeCandidates.push_back(p.first);
        }
        else if (p.second == maxFreq) 
        {
            modeCandidates.push_back(p.first);
        }
    }

    // 1. 산술평균 (반올림)
    cout << static_cast<int>(round((double)sum / N)) << '\n';

    // 2. 중앙값
    cout << nums[N / 2] << '\n';

    // 3. 최빈값
    if (modeCandidates.size() == 1)
        cout << modeCandidates[0] << '\n';
    else
        cout << modeCandidates[1] << '\n'; 

    // 4. 범위
    cout << nums.back() - nums.front() << '\n';

    return 0;
}
