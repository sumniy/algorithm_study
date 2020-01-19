#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    answer.push_back(0);
    
    int end_of_answer;
    
    for(int i=0; i<n-1; i++)
    {
        end_of_answer = answer.size() - 1;
        answer.push_back(0);
        
        for(int i=end_of_answer; i>=0; i--)
        {
            if(answer[i] == 0)
            {
                answer.push_back(1);
            }
            else answer.push_back(0);
        }
    }
    
    return answer;
}