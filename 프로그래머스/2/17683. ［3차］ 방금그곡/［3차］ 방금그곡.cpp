#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 특수 음을 다른 문자로 매핑하는 함수
string mapping(map<string, char>& p, string& m) {
    string temp = "";
    for (int i = 0; i < m.length(); i++) {
        if (i + 1 < m.length() && m[i + 1] == '#') {
            temp += p[m.substr(i, 2)];  // C# -> Z 같은 맵핑
            i++;  // #을 넘기기 위해 i를 하나 증가시킴
        } else {
            temp += m[i];  // #이 없는 음은 그대로 추가
        }
    }
    return temp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int bTime = 0;  // 가장 긴 재생 시간을 추적할 변수
    string melody = "", title = "";
    
    // 음을 변환하기 위한 맵
    map<string, char> p;
    p["C#"] = 'Z';
    p["D#"] = 'X';
    p["F#"] = 'C';
    p["G#"] = 'V';
    p["A#"] = 'B';

    // 기억한 멜로디를 매핑하여 변환
    melody = mapping(p, m);

    // 음악 정보를 처리
    for (int i = 0; i < musicinfos.size(); i++) {
        string music = "", tmp = "";
        
        // 시작 시간과 종료 시간 계산
        int sHour = stoi(musicinfos[i].substr(0, 2));
        int sMin = stoi(musicinfos[i].substr(3, 2));
        int eHour = stoi(musicinfos[i].substr(6, 2));
        int eMin = stoi(musicinfos[i].substr(9, 2));

        // 재생 시간 계산 (분 단위)
        int duration = (eHour * 60 + eMin) - (sHour * 60 + sMin);
        
        // 제목과 악보 정보를 분리
        int j = 12;
        while (musicinfos[i][j] != ',') j++;  // 제목 끝 찾기
        title = musicinfos[i].substr(12, j - 12);  // 제목 추출
        tmp = musicinfos[i].substr(j + 1);  // 악보 부분

        // 악보 매핑
        music = mapping(p, tmp);
        
        // 음악 길이가 재생 시간보다 짧으면 반복해서 음악을 채운다
        if (music.size() < duration) {
            string fullMusic = music;
            while (fullMusic.size() < duration) {
                fullMusic += music;
            }
            music = fullMusic.substr(0, duration);  // 필요한 만큼 자르기
        } else {
            music = music.substr(0, duration);  // 음악이 길면 잘라서 사용
        }

        // 기억한 멜로디가 해당 음악에 포함되어 있는지 확인
        if (music.find(melody) != string::npos) {
            if (bTime < duration) {
                answer = title;  // 가장 긴 시간이면 답을 갱신
                bTime = duration;  // 재생 시간 갱신
            }
        }
    }
    return answer;
}
