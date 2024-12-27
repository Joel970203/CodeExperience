#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    char direction;
    bool found = false;
    int tempX, tempY;
    int maxX = park[0].size();
    int maxY = park.size();
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                tempX = j;
                tempY = i;
                found = true;
                break;
            }

        }
        if(found) break;
    }

    for (int i = 0; i < routes.size(); i++)
    {
        int prevX = tempX;
        int prevY = tempY;
        int cnt = stoi(routes[i].substr(2));
        for (int j = 0; j < cnt; j++)
        {
            direction = routes[i].substr(0, 1)[0];

            if (direction == 'E')
            {
                tempX += 1;
                if (tempX >= 0 && tempX < maxX && tempY >= 0 && tempY < maxY)
                {
                    if (park[tempY][tempX] == 'X')
                    {
                        tempX = prevX;
                        break;
                    }
                }
                else // 밖으로 삐져나간애들
                {
                    tempX = prevX;
                    break;
                }
            }
            
            if (direction == 'W')
            {
                tempX -= 1;
                if (tempX >= 0 && tempX < maxX && tempY >= 0 && tempY < maxY)
                {
                    if (park[tempY][tempX] == 'X')
                    {
                        tempX = prevX;
                        break;
                    }
                }
                else
                {
                    tempX = prevX;
                    break;
                }
            }
            if (direction == 'S')
            {
                tempY += 1;
                if (tempX >= 0 && tempX < maxX && tempY >= 0 && tempY < maxY)
                {
                    if (park[tempY][tempX] == 'X')
                    {
                        tempY = prevY;
                        break;
                    }
                }
                else
                {
                    tempY = prevY;
                    break;
                }
            }

            if (direction == 'N')
            {
                tempY -= 1;
                if (tempX >= 0 && tempX < maxX && tempY >= 0 && tempY < maxY)
                {
                    if (park[tempY][tempX] == 'X')
                    {
                        tempY = prevY;
                        break;
                    }
                }
                else
                {
                    tempY = prevY;
                    break;
                }
            }
        }
    }
    /*
    oso
    ooo
    oxo
    ooo
    */
    answer.push_back(tempY);
    answer.push_back(tempX);
    return answer;

}