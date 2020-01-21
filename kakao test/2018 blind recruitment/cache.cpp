#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> city;
    
    string input;
    
    if(cacheSize == 0 )
        return answer = cities.size() * 5;
    
    for(int i=0;i<cities.size();i++)
    {
        input = cities[i];
        transform(input.begin() , input.end(), input.begin(), ::tolower);
        
        auto it = find(city.begin(), city.end(), input);
        
        if(it != city.end())
        {
            answer+=1;
            city.erase(it);
            city.push_back(input);
        }
        else if(city.size() == cacheSize && it == city.end())
        {
            answer += 5;
            city.erase(city.begin());
            city.push_back(input);
        }
        else
        {
            answer += 5;
            city.push_back(input);
        }
        
    }
        
    
    
    return answer;
}