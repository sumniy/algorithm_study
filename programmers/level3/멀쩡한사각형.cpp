#include<algorithm>
using namespace std;

int Gcd(int big, int small)
{
  if(small > big) swap(big, small);

  int tmp;
  while(small != 0)
  {
    tmp = big%small;
    big = small;
    small = tmp;
  }

  return big;
}

long long solution(int w,int h) {
    long long answer = 1;

    int gcd = Gcd(w, h);

    answer = (long long)w*(long long)h - ((w/gcd) + (h/gcd) - 1)*gcd;

    return answer;
}