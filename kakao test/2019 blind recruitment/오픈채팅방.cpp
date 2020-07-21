#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

#define endl "\n"

using namespace std;

vector<string> solution(vector<string> record) {    
    map<string, string> id_name;
    vector<string> uids;
    vector<bool> in_out;
    
    for(auto msg : record)
    {
        stringstream ss(msg);
        ss.str(msg);
        string cmd = "";
        string uid = "";
        string name = "";
        
        ss >> cmd >> uid;
            
        if(cmd == "Enter" || cmd == "Change")
        {
            ss >> name;
            id_name[uid] = name;
            if(cmd == "Enter")
            {
                uids.push_back(uid);
                in_out.push_back(true);
            }
        }
        else
        {
            uids.push_back(uid);
            in_out.push_back(false);
        }
    }
    
    vector<string> answer;
    for(int i=0;i<uids.size();i++)
    {
        if(in_out[i])
        {
            answer.push_back(id_name[uids[i]] + "님이 들어왔습니다.");
        }
        else
        {
            answer.push_back(id_name[uids[i]] + "님이 나갔습니다.");
        }
    }

    return answer;
}