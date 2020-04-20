// 기존 풀이법의 시간 복잡도를 개선한 버전
// 백준사이트의 다른 사람의 풀이를 참조

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair < int, int> pii;

int N, M, Year;
int food[10][10];
vector<pii> ground[10][10];
int add_food[10][10];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void init()
{
  scanf("%d %d %d", &N, &M, &Year);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      {
        scanf("%d", &add_food[i][j]);
        food[i][j] = 5;
      }
      // input >> add_food[i][j], food[i][j] = 5;
  for (int i = 0, x, y, z; i < M; i++)
  {
    // input >> x >> y >> z;
    scanf("%d %d %d", &x, &y, &z);
    ground[--x][--y].push_back({z, 1});
  }
}

void spring_and_summer()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int dead_trees = 0;
      for (int k = ground[i][j].size() - 1; k >= 0; k--)
      { 
        int tree_age = ground[i][j][k].first;
        int cnt = ground[i][j][k].second;
        int eat_food = tree_age * cnt;
        

        if (food[i][j] >= eat_food)
        {
          food[i][j] -= eat_food;
          ground[i][j][k].first++;
        }
        else
        {
          int alive_cnt = food[i][j] / tree_age;
          int dead_cnt = cnt - alive_cnt;
          dead_trees += dead_cnt * (tree_age / 2);

          if(alive_cnt == 0)
          {
            ground[i][j].erase(ground[i][j].begin() + k);
            continue; 
          }

          food[i][j] -= alive_cnt * tree_age;
          ground[i][j][k].second = alive_cnt;
          ground[i][j][k].first++;
        }
        
      }
      food[i][j] += dead_trees;
    }
  }
}

void autumn()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int size = ground[i][j].size();
      for (int k = 0; k < size; k++)
      {
        int tree_age = ground[i][j][k].first;
        int cnt = ground[i][j][k].second;

        if (tree_age % 5 == 0)
        {
          for (int dir = 0; dir < 8; dir++)
          {
            int nr = i + dr[dir];
            int nc = j + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
              continue;
            
            if(ground[nr][nc].size()==0 || ground[nr][nc].back().first != 1)
              ground[nr][nc].push_back({1, cnt});
            else
              ground[nr][nc].back().second += cnt;
          }
        }
      }
    }
  }
}

void winter() 
{
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      food[i][j] += add_food[i][j];
    }
  }
}

int get_total_trees()
{
  int total=0;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      for(int k=ground[i][j].size()-1;k>=0;k--)
      {
        total += ground[i][j][k].second;
      }
    }
  }
  return total;
}

int main()
{
  init();

  for(int i=0;i<Year;i++)
  {
    spring_and_summer();
    autumn();
    winter();
  }

  printf("%d", get_total_trees());
  // cout<<get_total_trees()<<endl;
  return 0;
}