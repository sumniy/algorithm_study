#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int i, temp, temp2;
    string row = "";
    for(i=0;i<n;i++)
    {
        temp = arr1[i] | arr2[i];
        
        for(int j=0;j<n;j++)
        {
            temp2 = temp%2;
        temp = temp>>1;
        
        if(temp2 == 1)
        {
            row = '#' + row;
        }
        else
        {
            row = ' ' + row;
        }
        }
        
        
        answer.push_back(row);
        row = "";
    }
    
    
    return answer;
}