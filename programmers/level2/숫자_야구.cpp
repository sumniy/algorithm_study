#include <string>
#include <vector>

using namespace std;

pair<int, int> CheckStrikeBall(int number, int question)
{
    string number_str = to_string(number);
    string question_str = to_string(question);
    int strike=0;
    int ball=0;
    
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(number_str[i] == question_str[j])
            {
                if(i == j) strike++;
                else ball++;
                break;
            }
        }
    }
    return {strike, ball};
}

bool IsNumberException(int number)
{
    string s = to_string(number);
    if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) return true;
    if(s[1] == '0' || s[2] == '0') return true;
    return false;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int question_size = baseball.size();
    
    for(int number = 123; number <= 987; ++number)
    {
        if(IsNumberException(number)) continue;
        bool correct = true;
        
        for(int i=0;i<question_size;++i)
        {
            int question = baseball[i][0];
            int strike = baseball[i][1];
            int ball = baseball[i][2];
            
            pair<int, int> temp = CheckStrikeBall(number, question);
            
            if(strike == temp.first && ball == temp.second)
                continue;
            else
            {
                correct = false;
                break;
            }
        }
        if(correct) answer++;
    }
    
    return answer;
}