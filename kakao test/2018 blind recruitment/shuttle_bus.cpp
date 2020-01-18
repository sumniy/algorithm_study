#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int convert(string s)
{
    string hours ="";
    string minutes ="";
    
    hours = s.substr(0,2);
    minutes = s.substr(3, 2);
    
    int result = stoi(hours)*60 + stoi(minutes); 
    
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    int start = 540;
    
    vector<int> tt;
    for(int i=0;i<timetable.size();i++)
        tt.push_back(convert(timetable[i]));
    
    sort(tt.begin(),tt.end());
    
    queue<int> q;
    
    for(int i=0;i<tt.size();i++)
        q.push(tt[i]);
    
    vector< vector<int> > table;
    vector<int> temp;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        count=0;
        temp.clear();
        while(q.front() <= start && !q.empty())
        {
            count++;
            temp.push_back(q.front());
            q.pop();
            if(count==m) break;
        }
        start+=t;
        table.push_back(temp);
    }
    int i;
    int ans=0;
    
    for(i=n-1;i>=0;i--)
    {
        if(table[i].size() < m)
        {
            ans = 540 + t*i;
            break;
        }
        else if(table[i].size()==m)
        {
            ans = table[i][m-1] -1;
            break;
        }
    }

    int hr, min;
    hr = ans/60;
    min = ans%60;
    
    string hours, minutes;
    
    hours = to_string(hr);
    minutes = to_string(min);
    
    if(hours.length()==1) hours = "0"+hours;
    if(minutes.length()==1) minutes = "0"+minutes;
    
    answer = hours + ":" + minutes;
    
    return answer;
}