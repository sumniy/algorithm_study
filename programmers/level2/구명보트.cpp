#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<int>());
    deque<int> people_deque(people.begin(), people.end());
    
    while(!people_deque.empty())
    {
        answer++;
        if(people_deque.size() == 1) break;
        
        if(people_deque.front() + people_deque.back() <= limit)
        {
            people_deque.pop_back();
        }
        people_deque.pop_front();
    }
    
    return answer;
}