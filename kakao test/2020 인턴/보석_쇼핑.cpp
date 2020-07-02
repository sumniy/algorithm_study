#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0,0};
    
    set<string> gems_set;
    for(auto& gem : gems)
    {
        gems_set.insert(gem);
    }
    int num_of_gems_kind = gems_set.size();
    
    unordered_map<string, int> gems_cnt;
    int left = 0;
    int min = 100001;
    for(int right=0; right<gems.size();right++)
    {
        gems_cnt[gems[right]]++;
        if(gems_cnt.size() == num_of_gems_kind)
        {
            while(gems_cnt[gems[left]] >= 2)
            {
                gems_cnt[gems[left]]--;
                left++;
            }
            
            int length_of_section = right - left + 1;
            if(length_of_section < min)
            {
                min = length_of_section;
                answer[0] = left+1;
                answer[1] = right+1;
            }
        }
    }
    
    return answer;
}