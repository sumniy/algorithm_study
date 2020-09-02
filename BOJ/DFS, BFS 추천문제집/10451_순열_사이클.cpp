#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl "\n"

void dfs(int start, vector<int>& permutation, vector<bool>& is_visited) {

  is_visited[start] = true;

  int next = permutation[start];
  if(is_visited[next] == true) {
    return;
  } else {
    dfs(permutation[start], permutation, is_visited);
  }
}

int main()
{
  freopen("10451_input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tc; 
  cin >> tc;

  for(int i=0;i<tc;i++) {
    int cycle_num = 0;
    int N;
    cin>>N;

    vector<int> permutation(N+1, 0);
    vector<bool> is_visited(N+1, false);

    for(int i=1;i<=N;i++) {
      int input;
      cin >> input;
      permutation[i] = input;
    }

    for(int i=1;i<=N;i++) {
      if(is_visited[i] == false) {
        cycle_num++;
        dfs(i, permutation, is_visited);
      }
    }

    cout<<cycle_num<<endl;
  }

  return 0;
}