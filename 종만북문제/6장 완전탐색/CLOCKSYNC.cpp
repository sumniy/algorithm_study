

// 오답




#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int switch_clicked_num[10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

vector<vector<int>> swch = 
{
    {0,1,2}, {3,7,9,11}, {4,10,14,15}, {0,4,5,6,7}, {6,7,8,10,12},
    {0,2,14,15}, {3,14,15}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13}
};

// 12가 아닌 시계의 인덱스들을 찾는다
vector<int> CheckClock(vector<int>& clock)
{
    vector<int> ret;
    for(int i=0;i<clock.size();i++)
    {
        if(clock[i] != 12) ret.push_back(i);
    }
    return ret;
}

// 누른 스위치에 따른 시계의 변화를 주는 함수
void ClickSwitch(vector<int>& clock, int switch_num)
{
    vector<int> clicked_switch = swch[switch_num];
    for(int i=0;i<clicked_switch.size();i++)
    {
        int idx = clicked_switch[i];
        clock[idx] += 3;
        if(clock[idx] == 15) clock[idx] = 3;
    }
}

// 12가 아닌 시계와 스위치의 숫자가 많이 겹치는 스위치를 찾아 주는 함수
int FindSwitch(vector<int>& checked_clock)
{
    int ret = 0 ;
    int max = -1;


    for(int i=0;i<10;i++)
    {
        int matched = 0;
        for(int j=0;j<swch[i].size();j++)
        {
            for(int k=0;k<checked_clock.size();k++)
            {
                if(checked_clock[k] == swch[i][j])
                {   
                    matched++;
                    break;
                }
            }
        }
        if(matched > max && switch_clicked_num[i] < 3)
        {
            max = matched;
            ret = i;
        }
    }
    switch_clicked_num[ret]++;
    return ret;
}


int main() {
    freopen("CLOCKSYNC_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    cin >> C;

    for(int tc =0;tc<C;tc++)
    {
        int answer = 0;
        vector<int> clock;
        for(int i=0;i<16;i++)
        {
            int temp;
            cin >> temp;
            clock.push_back(temp);
        }
        
        
        vector<int> checked_clock = CheckClock(clock);

        while(!checked_clock.empty())
        {
            int switch_to_click = FindSwitch(checked_clock);
            ClickSwitch(clock, switch_to_click);
            answer++;
            checked_clock = CheckClock(clock);
        }   
        cout<<answer<<endl;
    }
    return 0;
}