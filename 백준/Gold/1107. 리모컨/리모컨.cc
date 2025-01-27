#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_broken[10]; 

bool is_valid_channel(int channel) {
    string channel_str = to_string(channel);
    for (char ch : channel_str) {
        if (is_broken[ch - '0']) return false; 
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    // 고장난 버튼 입력
    for (int i = 0; i < M; i++) {
        int broken_button;
        cin >> broken_button;
        is_broken[broken_button] = true;
    }

    int current_channel = 100; 
    int min_press = abs(N - current_channel);

    for (int channel = 0; channel <= 1000000; channel++) {
        if (is_valid_channel(channel)) { 
            int press_count = to_string(channel).length(); 
            press_count += abs(channel - N); 
            min_press = min(min_press, press_count); 
        }
    }

    cout << min_press << endl; 
    return 0;
}
