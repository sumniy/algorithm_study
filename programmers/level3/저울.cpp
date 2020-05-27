#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> weight) {
    int answer = 1;
    sort(weight.begin(), weight.end());
    
    int size = weight.size();
    
    for(int i=0;i<size;i++)
    {
        if(answer >= weight[i]) answer += weight[i];
        else break;
    }
    
    
    return answer;
}