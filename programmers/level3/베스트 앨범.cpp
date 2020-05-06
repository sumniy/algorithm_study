#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

typedef pair <int, string> pis;
typedef pair <int, int> pii;

bool cmp(tuple<string, int, int>& a, tuple<string, int, int>& b)
{
  if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
  if(get<1>(a) == get<1>(b))
  {
    return get<2>(a) < get<2>(b);
  }
  return get<1>(a) > get<1>(b);
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    priority_queue<pis, vector<pis>, less<pis>> pq;

    vector<tuple<string, int, int>> hash;

    
    map<string, int> genres_total_play;
    
    int n = genres.size();
    for(int i=0;i<n;i++)
    {
        // 먼저 장르 별 재생 수 구해주고
        genres_total_play[genres[i]] += plays[i];
        // 해쉬에 넣어주기
        hash.push_back(make_tuple(genres[i], plays[i], i));
        // hash.insert({genres[i],pii(plays[i], i)});
    }

    for(auto& i : genres_total_play)
    {
      pq.push({i.second, i.first});
    }
    
    sort(hash.begin(), hash.end(), cmp);

    int size = pq.size();


    for(int i=0;i<size;i++)
    {
      pis temp = pq.top();
      pq.pop();
      string genre = temp.second;

      int j;
      for(j=0;j<hash.size();j++)
      {
        if(get<0>(hash[j]) == genre)
        {
          break;
        }
      }

      answer.push_back(get<2>(hash[j]));
      if(get<0>(hash[j+1]) == genre)
      {
        answer.push_back(get<2>(hash[j+1]));
        continue;
      }
    }
    
    return answer;
}