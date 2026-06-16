#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    // unique 함수 사용.
    // arr.erase(unique(arr.begin(),arr.end()),arr.end());
    // answer = arr;

    for(int i= 0; i<arr.size(); i++)
    {
        if(!(arr[i] == arr[i+1]))
        {
            answer.push_back(arr[i]);
        }
    }


    return answer;
}