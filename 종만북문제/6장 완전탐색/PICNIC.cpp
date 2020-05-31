#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
// 테스트 케이스의 수 C
// 각 케이스의 첫 줄에는 학생의 수 n(2<=n<=10), 친구 쌍의 수 m(0<=m<=n*(n-1)/2)이 주어진다.
// 다음 줄에 m개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어진다.

// 0번 부터 시작해서 가능한 쌍을 모두 선택한다.
// 그 다음, 다음 번호로 호출하여 선택되지 않은 친구 쌍을 선택하도록 한다.
// base case는 n 과 선택된 친구 수가 같을 때

int FindAllPairs(vector<pii> &pairs, vector<bool> &selected, int n, int num_selected, int start)
{
  if (n == num_selected)
  {
    // cout<<endl;
    return 1;
  }

  int ret = 0;
  int size = pairs.size();
  
  for(int i=start;i<size;i++)
  {
    int left = pairs[i].first;
    int right = pairs[i].second;

    if(!selected[left] && !selected[right])
    {
      selected[left] = true;
      selected[right] = true;
      // cout<<"("<<left<<", "<<right<<")  ";
      ret += FindAllPairs(pairs, selected, n, num_selected + 2, i + 1);
      selected[left] = false;
      selected[right] = false;
    }
  }
  // cout<<endl;
  return ret;
}

int main()
{
  ifstream input("PICNIC_input.txt");
  int C;
  input >> C;

  for (int tc = 0; tc < C; ++tc)
  {
    int n, m;
    input >> n >> m;
    vector<pii> pairs;
    for (int i = 0; i < m; i++)
    {
      int f1, f2;
      input >> f1 >> f2;
      pairs.push_back({f1, f2});
    }

    vector<bool> selected(n, false);

    int answer = FindAllPairs(pairs, selected, n, 0, 0);
    cout<<answer<<endl;
  }

  return 0;
}