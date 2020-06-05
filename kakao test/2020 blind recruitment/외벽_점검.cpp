#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool repaired[201] = {false, };
int weak_size;

int repair(vector<int>& weak, vector<int>& dist,int n, int repaired_num ,int friends)
{
    if(friends >= dist.size()) return 99999;
    if(repaired_num == weak_size)
    {
        return friends;
    }
    
    int ret = 99999;
    
    for(int i=0;i<dist.size();i++)
    {
        int distance = dist[i];

        for(int j=0;j<weak_size;j++)
        {
            // 시계 방향
            int idx = weak[j];
            
            while(distance >= 0)
            {
                if(repaired[idx] == false)
                {
                    repaired[idx] = true;
                }
            }

        }
    }
}


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    weak_size = weak.size();
    sort(dist.begin(), dist.end(), less<int>());
    return answer;
}