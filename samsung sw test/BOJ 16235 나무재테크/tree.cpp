#include <iostream>
#include <vector>
#include <deque>
#include <fstream>

using namespace std;

int test = 0;

class LandInformation
{
public:
  int food;
  deque<int> trees;
  vector<int> dead_trees;

  LandInformation()
  {
    food = 5;
  }

  int get_trees_num()
  {
    if (trees.empty())
      return 0;
    return trees.size();
  }

  void spring()
  {
    if (trees.empty())
      return;

    for (deque<int>::iterator iter = trees.begin(); iter != trees.end(); iter++)
    {
      if (food >= *iter)
      {
        food -= *iter;
        (*iter)++;
      }
      else
      {
        while (iter != trees.end())
        {
          dead_trees.push_back(*iter);
          iter = trees.erase(iter);
        }
        break;
      }
    }
  }

  void summer()
  {
    if (dead_trees.empty())
      return;
    for (auto &i : dead_trees)
    {
      food += i / 2;
    }
    dead_trees.clear();
  }

  int autumn()
  {
    if (trees.empty())
      return 0;
    int trees_5n = 0;
    for (auto &i : trees)
    {
      if (i % 5 == 0)
        trees_5n++;
    }
    return trees_5n;
  }

  //winter
  void addfood(int f)
  {
    food += f;
  }
};

int N, M, K, answer;
int A[12][12];
LandInformation land[12][12];

void init()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream input("input.txt");

  // cin>>N>>M>>K;
  input >> N >> M >> K;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      // cin>>A[i][j];
      input >> A[i][j];

  for (int i = 0; i < M; i++)
  {
    int x, y, z;
    // cin>>x>>y>>z;
    input >> x >> y >> z;

    land[x][y].trees.push_back(z);
  }
}

void YearK()
{

  for (int year = 0; year < K; year++)
  {

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        land[i][j].spring();
      }
    }

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        land[i][j].summer();
      }
    }

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        int temp = land[i][j].autumn();
        if (temp != 0)
        {
          for (int t = 0; t < temp; t++)
          {
            land[i - 1][j].trees.push_front(1);
            land[i - 1][j + 1].trees.push_front(1);
            land[i][j + 1].trees.push_front(1);
            land[i + 1][j + 1].trees.push_front(1);
            land[i + 1][j].trees.push_front(1);
            land[i + 1][j - 1].trees.push_front(1);
            land[i][j - 1].trees.push_front(1);
            land[i - 1][j - 1].trees.push_front(1);
          }
        }
      }
    }

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        land[i][j].addfood(A[i][j]);
      }
    }
  }
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      answer += land[i][j].get_trees_num();
    }
  }
}

int main()
{
  answer = 0;
  init();
  YearK();
  cout << answer << endl;
  return 0;
}