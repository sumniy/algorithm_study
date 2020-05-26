#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
  return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 1;

    sort(routes.begin(), routes.end(), cmp);
    int size = routes.size();
    int tmp = routes[0][1];
    for(int i=0;i<size-1;i++)
    {
      // 지금 tmp의 구간안에서 가장 빨리 빠져나가는 차량을 기준으로 tmp를 다시 잡는다. 차량이 빠져나가는 순간이 그 구간에 겹치는 차량의 수가 최대인 순간이 되기 때문이다.
      if(tmp > routes[i][1]) tmp = routes[i][1];

      // 먼저 출발한 차들이 다 빠져나간뒤의 시간에 i+1번째 차량이 출발한다면 감시 카메라가 필요한 새로운 구간이 생기는 것이다
      if(routes[i+1][0] > tmp)
      {
        answer++;
        tmp = routes[i+1][1];
      }
    }

    

    return answer;
}