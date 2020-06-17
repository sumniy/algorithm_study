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

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int sum = 0;
    
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
    
    int cnt = 0;
    int min_value = 0;
    while(!foods.empty()){
        
        min_value = foods[0].times;
        size = foods.size();
        cnt = min_value * size;
        cout<<"min_value = "<<min_value<<", size = "<<size<<", cnt = "<<cnt<<", k = "<<k<<endl;
        
        if(cnt > k)
        {
            
            answer = k % size;
            cout<<"Find => answer = "<<answer<<", index = "<<foods[answer].init_index<<endl;
            cout<<foods[2].init_index<<endl;
            break;
        }
        else
        {
            k -= cnt;
            foods.pop_front();
            for(auto& food : foods)
            {
                food.times -= min_value;
            }
        }
        
    }
    if(foods.empty()) return -1;
    
    answer = foods[answer].init_index;
    
    return answer+1;
}