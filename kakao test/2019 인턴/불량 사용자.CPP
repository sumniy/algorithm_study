#include <string>
#include <vector>
#include <set>

using namespace std;

// dfs 활용
// user_id 에서 banned_id의 개수 k개가 매핑되는 경우를 set으로 넣어서 정답 수 확인
// set의 size가 k개면 answer++하고 return;
// banned_id에서 user_id를 순회하면서 매핑되면 다음 banned_id에 대해 user_id를 확인하도록 dfs를 호출하고
// 다음 user_id를 검사하도록 순회
#define SIZE 8

bool visited[SIZE];
set<string> banned_user_set;

bool is_matched(string& uid, string& bid)
{
  int uid_size = uid.size();
  int bid_size = bid.size();
  if (uid_size != bid_size)
    return false;

  for (int i = 0; i < uid_size; i++)
  {
    if (bid[i] == '*')
      continue;
    if (bid[i] != uid[i])
      return false;
  }
  return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, int index)
{
  if (index == banned_id.size())
  {
    string ids = "";
    for (int i = 0; i < SIZE; i++)
    {
      if (visited[i])
      {
        ids += i;
      }
    }
    banned_user_set.insert(ids);
    return;
  }

  string temp = banned_id[index];
  for (int j = 0; j < user_id.size(); j++)
  {
    if (!visited[j] && is_matched(user_id[j], temp))
    {
      visited[j] = true;
      dfs(user_id, banned_id, index+1);
      visited[j] = false;
    }
  }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
  int answer = 0;
  dfs(user_id, banned_id, 0);
  answer = banned_user_set.size();
  return answer;
}