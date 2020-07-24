#include <string>
#include <vector>

using namespace std;

// 이진수의 첫 번째 수(가장 오른쪽 숫자)는 0 혹은 1의 값을 가지므로
// 그 숫자를 2로 나누었을 때의 나머지는 이진수의 첫 번째 수와 같다는 걸 알 수 있다.
// 1. 이 특성을 활용하여 쉬프트 연산을 하면서 자연수 n의 이진수일 때의 1의 개수를 센다.
// 2. n+1부터 1씩 증가시키면서 같은 방법으로 1의 개수를 센다.
// 3. 2번의 1의 개수가 1번의 결과와 같을 때 까지 반복한다.

int solution(int n) {
    int answer = 0;
    int n_next = n;
    int cnt_one = 0;
    
    while(n)
    {
        if(n % 2 == 1)
        {
            ++cnt_one;
        }
        n = n >> 1;
    }
    
    int cnt_one_next = 0;
    while(cnt_one != cnt_one_next)
    {
        cnt_one_next = 0;
        int n_next_temp = ++n_next;
        while(n_next_temp)
        {
            if(n_next_temp%2 == 1)
                ++cnt_one_next;
            n_next_temp = n_next_temp >> 1;
        }
    }
    answer = n_next;
    return answer;
}