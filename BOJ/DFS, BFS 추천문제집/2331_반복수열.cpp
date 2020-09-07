#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;
#define endl "\n"

int getNextNumber(int A, int P) {
  int result = 0;
  while(A != 0) {
    int temp = A%10;
    result += round(pow(temp, P));
    A /= 10;
  }
  return result;
}

int main()
{
  freopen("2331_input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, P;
  cin >> A >> P;

  unordered_map<int, bool> map;
  vector<int> answer;

  while(map[A] == false) {
    answer.push_back(A);
    map[A] = true;
    A = getNextNumber(A, P);
  }

  auto it = find(answer.begin(), answer.end(), A);
  int index = distance(answer.begin(), it);

  cout<<index<<endl;

  return 0;
}