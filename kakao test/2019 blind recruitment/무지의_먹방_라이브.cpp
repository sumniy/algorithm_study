#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

class food{
public:
    int times;
    int init_index;
    
    bool operator<(food a)
    {
        return this->times < a.times;
    }
};

bool cmp(food a, food b)
{
    return a.init_index < b.init_index;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long sum = 0;
    
    deque<food> foods;
    int size = food_times.size();
    for(int i=0;i<size;i++)
    {
        food temp;
        temp.init_index = i;
        temp.times = food_times[i];
        sum += food_times[i];
        foods.push_back(temp);
    }
    
    if(sum <= k) return -1;
    
    sort(foods.begin(), foods.end());
    
    long long cnt = 0;
    long long min_value = 0;
    while(!foods.empty()){
        
        
        size = foods.size();
        cnt = (foods[0].times-min_value) * size;
        min_value = foods[0].times;
        
        if(cnt >= k)
        {
            
            answer = k % size;
            break;
        }
        else
        {
            k -= cnt;
            foods.pop_front();
        }
        
    }
    
    sort(foods.begin(), foods.end(), cmp);
    answer = foods[answer].init_index;
    
    return answer+1;
}