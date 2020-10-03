#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define endl "\n"

struct gem {
  int weight;
  int value;
  gem(int w, int v) {
    weight = w;
    value = v;
  }
  bool operator<(gem other) {
    return this->weight < other.weight;
  }
};

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int gem_num, bag_num;
  cin >> gem_num >> bag_num;

  vector<gem> gems;
  for(int i=0;i<gem_num;i++) {
    int weight, value;
    cin >> weight >> value;
    gems.push_back(gem(weight, value));
  }

  deque<int> bags;
  for(int i=0;i<bag_num;i++) {
    int carry_weight;
    cin >> carry_weight;
    bags.push_back(carry_weight);
  }

  sort(gems.begin(), gems.end());
  sort(bags.begin(), bags.end());

  long long sum = 0;
  int gems_idx = 0;

  priority_queue<int> pq;

  for(auto b : bags) {
    while(gems_idx < gem_num && gems[gems_idx].weight <= b)
      pq.push(gems[gems_idx++].value);

    if(!pq.empty()) {
      // cout<<pq.top()<<endl;
      sum += pq.top();
      pq.pop();
    }
  }

  cout<<sum<<endl;

  return 0;
}