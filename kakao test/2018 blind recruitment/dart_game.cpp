#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int convert(string split)
{
    if(split[1] == 48) return 10;
    else{
        return split[0]-48;
    }
}

int find_Area(string split)
{
    if(split.find("S") != string::npos) return 1;
    if(split.find("D") != string::npos) return 2;
    if(split.find("T") != string::npos) return 3;
}

int find_option(string split)
{
    if(split.find('#') != string::npos) return -1;
    else if(split.find('*') != string::npos) return 2;
    else return 1;
}

int solution(string dartResult) {
    int answer = 0;
    
    string s[3];
    s[0] = "";
    s[1] = "";
    s[2] = "";
    int pos=0;
    
    s[pos] += dartResult[0];
    
    for(int i=1;i<dartResult.length();i++)
    {
        if(dartResult[i] >=48 && dartResult[i] <= 57)
        {
            if(!(dartResult[i-1] >=48 && dartResult[i-1] <= 57))
            pos++;
        }
        s[pos] += dartResult[i];
    }
    
    int score[3] ={0,};
    int area=0;
    int option=0;
    
    for(int i=0;i<3;i++)
    {
        score[i] = convert(s[i]);
        area = find_Area(s[i]);
        option = find_option(s[i]);
        
        score[i] = pow(score[i],area)*option;
        if(option == 2 && i>0) score[i-1] *= 2;
    }
    
    answer = score[0] + score[1] + score[2];
    
    return answer;
}