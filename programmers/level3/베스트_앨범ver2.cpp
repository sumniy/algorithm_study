#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Song
{
public:
  int num;
  string genre;
  int plays;
  Song(int n, string g, int p) : num(n), genre(g), plays(p){}

  bool operator<(Song other)
  {
    if (this->plays == other.plays) return this->num < other.num;

    return this->plays > other.plays;
  }
};

bool cmp(pair<string, int> a, pair<string, int> b)
{
  return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
  vector<int> answer;

  map<string, int> plays_by_genres;
  map<string, vector<Song>> songs_by_genres;

  int n = genres.size();
  for (int i = 0; i < n; i++)
  {
    plays_by_genres[genres[i]] += plays[i];
    songs_by_genres[genres[i]].push_back(Song(i, genres[i], plays[i]));
  }
  // plays_by_genres를 vector로 복사해서 sort by value 실행 -> 재생 수가 많은 장르 순으로 정렬
  vector<pair<string, int>> plays_by_genres_(plays_by_genres.begin(), plays_by_genres.end());
  sort(plays_by_genres_.begin(), plays_by_genres_.end(), cmp);

  for (auto &songs : songs_by_genres)
  {
    // 장르 내에서 재생 수가 많은 노래 순으로 정렬
    sort(songs.second.begin(), songs.second.end());
  }

  int size_of_genres = plays_by_genres_.size();

  for (int i = 0; i < size_of_genres; i++)
  {
    string genre = plays_by_genres_[i].first;

    answer.push_back(songs_by_genres[genre][0].num);
    if (songs_by_genres[genre].size() >= 2)
      answer.push_back(songs_by_genres[genre][1].num);
  }

  return answer;
}