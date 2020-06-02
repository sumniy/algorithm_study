#include <string>
#include <vector>

using namespace std;

int AssignBudget(vector<int> &budgets, int limit)
{
    int total=0;
    for(auto& budget : budgets)
    {
        if(budget < limit)
        {
            total += budget;
        }
        else total += limit;
    }
    return total;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;

    int left = 0;
    int right = 1000000000;
    int mid;
    int used;

    while(left<=right)
    {
        mid = (left + right)/2;
        if(M < mid)
        {
            right = mid - 1;
            continue;
        }
        
        used = AssignBudget(budgets, mid);

        if(used > M) 
        {
            right = mid - 1;
        }
        else if(used < M)
        {
            left = mid + 1;
        }
        else
        {
            //used == m
            break;
        }
    }
    answer = mid;
    return answer;
}

// left = 3
// right = 1,000,000,000
// 으로 잡고
// 이분 탐색을 시작
// mid = (left + right)/2
// 여기서 mid 는 상한액

// 상한액을 구한 후 상한액이 M보다 크면 
// right = mid -1;

// 상한액이 M 보다 작다면 
// 각 요청액에 대해 계산해서 배정된 금액 used를 구한다.
// used 가 M 보다 크다면
// right = mid -1;
// used 가 M 보다 작다면 
// left = mid + 1;

// left<=right 가 만족하지 않아질 때 mid 값

// 로 하고 
// 예산이 M 이니까 mid