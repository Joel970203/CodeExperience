#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string str1, string str2) 
{
    for (auto &c : str1) c = tolower(c);
    for (auto &c : str2) c = tolower(c);

    vector<string> arr1;
    vector<string> arr2;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            string tmp;
            tmp.push_back(str1[i]);
            tmp.push_back(str1[i + 1]);
            arr1.push_back(tmp);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string tmp;
            tmp.push_back(str2[i]);
            tmp.push_back(str2[i + 1]);
            arr2.push_back(tmp);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<string> interV;
    vector<string> unionV;

    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(interV));
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(unionV));

    int interSize = interV.size();
    int unionSize = unionV.size();

    double jacard = 0.0;
    if (unionSize == 0) jacard = 1.0;
    else jacard = (double)interSize / unionSize;

    return (int)(jacard * 65536);
}
