#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

const int INF = 99999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS+1] = 
{
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks)
{
    for(int i=0;i<CLOCKS;i++)
    {
        if(clocks[i] != 12) return false;
    }
    return true;
}

void push(vector<int>& clocks, int swch)
{
    for(int clock = 0; clock<CLOCKS; ++ clock)
    {
        if(linked[swch][clock] == 'x')
        {
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swch)
{
    if(swch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    
    int ret = INF;
    for(int cnt = 0; cnt<4;++cnt)
    {
        ret = min(ret, cnt + solve(clocks, swch+1));
        push(clocks, swch);
    }

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
        vector<int> clocks;
        for(int i=0;i<16;i++)
        {
            int temp;
            cin >> temp;
            clocks.push_back(temp);
        }

        answer = solve(clocks, 0);
        
        
        cout<<answer<<endl;
    }
    return 0;
}