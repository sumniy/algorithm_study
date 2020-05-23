#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

// 투 포인터 알고리즘 적용
// start와 end를 가리키는 두 개의 포인터를 이동시키며
// 조건을 만족하는 구간의 개수를 찾는다

// 이동 조건
// 1. end가 N과 같거나 클 때 루프를 빠져나온다. -> end >= N이 된다는 의미 = sum이 M보다 작은데, sum은 더이상 커질 수 없는 경우
// 2. sum == M 일 때는 cnt 값을 올려주고 start + 1, sum -= arr[start]
// 3. start에서 end 까지의 합을 sum이라 할 때 sum < M(타겟값)일 때는 end를 +1 해준 후 sum += arr[end];
// 4. sum > M일 때는 sum -= arr[start] 해준 후 start를 +1

int main()
{
  // freopen("input.txt", "r", stdin);
  int N, M;
  cin >> N >> M;
  vector<int> arr;
  int temp;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    arr.push_back(temp);
  }

  int start = 0, end = 0, sum = arr[0], cnt = 0;

  while (end < N)
  {
    if (sum == M)
    {
      cnt++;
      sum -= arr[start];
      start += 1;
      end += 1;
      sum += arr[end];
    }
    else if (sum > M)
    {
      sum -= arr[start];
      start += 1;
    }
    else if (sum < M)
    {
      end += 1;
      sum += arr[end];
    }
  }

  cout << cnt << endl;
}