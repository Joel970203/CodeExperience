#include <string>
#include <vector>

using namespace std;

// 버블 정렬
int sort(vector<int> array, vector<int> target)
{
    vector<int> arr2;

    for (int i = target[0] - 1; i < target[1]; i++)
    {
        arr2.push_back(array[i]);
    }

    for (int i = 0; i < arr2.size() - 1; i++)
    {
        for (int j = 0; j < arr2.size() - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    int xy = target[2] - 1; 
    return arr2[xy];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        answer.push_back(sort(array, commands[i]));
    }

    return answer;
}