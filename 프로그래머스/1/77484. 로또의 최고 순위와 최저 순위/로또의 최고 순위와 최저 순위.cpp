#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int match = 0;
    int match2 = 0;
    for(int i=0;i<lottos.size();i++)
    {
        if(lottos[i] == 0)
        {
            match++;
        }
    }

    for(int i=0;i<lottos.size();i++)
    {
        for(int j=0;j<win_nums.size();j++)
        {
           if(lottos[i] == win_nums[j])
           {
               match++;
               match2++;
           }
        }
    }

    switch(match)
    {
        case 0:
                answer.push_back(6);
                break;
        case 1:
                answer.push_back(6);
                break;
        case 2:
                answer.push_back(5);
                break;
        case 3:
                answer.push_back(4);
                break;
        case 4:
                answer.push_back(3);
                break;
        case 5:
                answer.push_back(2);
                break;
        case 6:
                answer.push_back(1);
                break;
    }


    switch(match2)
    {
        case 0:
                answer.push_back(6);
                break;
        case 1:
                answer.push_back(6);
                break;
        case 2:
                answer.push_back(5);
                break;
        case 3:
                answer.push_back(4);
                break;
        case 4:
                answer.push_back(3);
                break;
        case 5:
                answer.push_back(2);
                break;
        case 6:
                answer.push_back(1);
                break;
    }
    return answer;
}