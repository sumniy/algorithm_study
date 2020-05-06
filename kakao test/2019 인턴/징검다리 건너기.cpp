#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CanAcross(vector<int> &stones, int k, int mid)
{
  int size = stones.size();
  int cnt = 0;
  for (int i = 0; i < size; i++)
  {
    if (stones[i] - mid <= 0)
    {
      cnt++;
    }
    else
    {
      cnt = 0;
    }

    if (cnt >= k)
    {
      return false;
    }
  }
  return true;
}

int solution(vector<int> stones, int k)
{
  int answer = 0;

  int max = max_element(stones.begin(), stones.end());
  int min = min_element(stones.being(), stones.end());
  int mid;

  while (min < max)
  {
    mid = (max + min);
    if (CanAcross(stones, k, mid))
    {
      min = mid + 1;
    }
    else
    {
      max = mid - 1;
    }
  }
  answer = mid;
  return answer;
}