#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(),str2.begin(), ::toupper);
    
    vector<string> string1;
    vector<string> string2;
    
    string temp = "";
    double t=0.0;
    
    for(int i=0;i<str1.length()-1;i++)
    {
        temp = "";
        if(isupper(str1[i]) && isupper(str1[i+1]))
        {
            temp += str1[i];
            temp += str1[i+1];
            string1.push_back(temp);
        }
    }
    
    for(int i=0;i<str2.length()-1;i++)
    {
        temp = "";
        if(isupper(str2[i]) && isupper(str2[i+1]))
        {
            temp += str2[i];
            temp += str2[i+1];
            string2.push_back(temp);
        }
    }
    
//      for(int i=0;i<string1.size();i++)
//      {
//          cout<<string1[i]<<" ";
//      }
//     cout<<endl;
    
//     for(int i=0;i<string2.size();i++)
//      {
//          cout<<string2[i]<<" ";
//      }
//     cout<<endl;
    
    int size1, size2;
    size1 = string1.size();
    size2 = string2.size();
    
    if(size1 == 0 && size2 == 0) return 65536;
    else if(size1 == 0 || size2 == 0) return 0; 
    
    map <string, int> m1;
    map <string, int> m2;
    set <string> s;
    
//     for(int i=0;i<size1;i++)
//     {
//         s.insert(string1[i]);
//         if(m1.find(string1[i]) != m1.end())
//             m1[string1[i]]++;
//         else m1.insert(pair<string,int>(string1[i], 1));
//     }
    
//     for(int i=0;i<size2;i++)
//     {
//         s.insert(string2[i]);
//         if(m2.find(string2[i]) != m2.end())
//             m2[string2[i]]++;
//         else m2.insert(pair<string,int>(string2[i], 1));
//     }
    
    for(int i=0;i<size1;i++)
    {
        s.insert(string1[i]);
    }
    
    for(int i=0;i<size2;i++)
    {
        s.insert(string2[i]);
    }
    set<string>::iterator iter;
    for(iter = s.begin(); iter!=s.end(); iter++)
    {
        m1.insert(pair<string,int>(*iter, 0));
        m2.insert(pair<string,int>(*iter, 0));
    }
    
    
    for(int i=0;i<size1;i++)
    {
        m1[string1[i]]++;
    }
    
    for(int i=0;i<size2;i++)
    {
        m2[string2[i]]++;
    }
    
    double minimum, maximum;
    
    
    for(iter = s.begin(); iter!=s.end(); iter++)
    {
        minimum += min(m1[*iter], m2[*iter]);
        maximum += max(m1[*iter], m2[*iter]);
    }
    
    t = minimum/maximum;
    
    
    
    
    
    
    
    
    // cout<<str1<<" "<<str2<<endl;
    
    answer = t * 65536;
    return answer;
}