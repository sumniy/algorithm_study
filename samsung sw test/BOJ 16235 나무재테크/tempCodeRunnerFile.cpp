#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <algorithm>

using namespace std;

deque<int> land[12][12];
vector<int> dead_trees[12][12];
int food[12][12];
int N, M, K, answer;
int A[12][12];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void spring()
{
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
    {
      if (land[i][j].empty())
        continue;

      for (deque<int>::iterator iter = land[i][j].begin(); iter != land[i][j].end(); iter++)
      {
        if (food[i][j] >= *iter)
        {
          food[i][j] -= *iter;
          (*iter)++;
        }
        else
        {
          while (iter != land[i][j].end())
          {
            dead_trees[i][j].push_back(*iter);
            iter = land[i][j].erase(iter);
          }
          break;
        }
      }
    }
}

void summer()
{
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
    {
      if (dead_trees[i][j].empty())
        continue;
      else
      {
        for (auto &it : dead_trees[i][j])
        {
          food[i][j] += it / 2;
        }
        dead_trees[i][j].clear();
      }
    }
}

void autumn()
{
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
    {
      for (auto &tree : land[i][j])
      {
        if (tree % 5 == 0)
        {
          for (int dir = 0; dir < 8; dir++)
            land[i + dr[dir]][j + dc[dir]].push_front(1);
        }
      }
    }
}

void winter()
{
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      food[i][j] += A[i][j];
}

void init()
{
  ifstream input("input.txt");

  fill(&food[0][0], &food[12][12 + 1], 5);

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
    {
      land[i][j].clear();
      dead_trees[i][j].clear();
    }

  //cin>>N>>M>>K;
  input >> N >> M >> K;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
    {
      // cin>>A[i][j];
      input >> A[i][j];
    }

  for (int i = 0; i < M; i++)
  {
    int x, y, z;
    // cin>>x>>y>>z;
    input >> x >> y >> z;

    land[x][y].push_back(z);
  }
}

int main()
{
  answer = 0;

  // 초기화 및 입력
  init();

  for (int k = 0; k < K; k++)
  {
    spring();
    summer();
    autumn();
    winter();
  }

  // 총 나무 수 계산
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (land[i][j].empty())
        continue;
      answer += land[i][j].size();
    }
  }

  cout << answer << endl;
  return 0;
}