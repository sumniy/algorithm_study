#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct cmp{
  bool &operator<(pair<int, int>& left, pair<int, int>& right)
  {
    return left.second > right.second;
  }
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> cnt;
    stringstream ss;
    int temp;

    ss.str(s);

    while(ss>>temp)
    {
      cnt[temp]++;
    }

    vector<pair<int, int>> cnt_vec(cnt.begin(), cnt.end());

    sort(cnt_vec.begin(), cnt_vec.end(), cmp);

    int size = cnt_vec.size();
    for(int i=0;i<size;i++)
    {
      answer.push_back(cnt_vec[i]);
    }
    
    return answer;
}