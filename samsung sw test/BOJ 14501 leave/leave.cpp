#include <cstdio>
#include <fstream>

using namespace std;

int N, ans;
int T[16];
int P[16];
int max_benefit = 0;
int day = 1;
bool chk[16] = {
    false,
};

void FindAnswer()
{
    int t_day;
    if (max_benefit > ans && day <= N + 1)
    {
        ans = max_benefit;
    }

    for (int i = day; i <= N; i++)
    {
        if (!chk[i])
        {
            day += T[i];
            if(day > N + 1)
            {
                day -= T[i];
                day++;
                continue;
            }
            max_benefit += P[i];
            for(int j=i;j<i+T[i];j++)
                chk[j] = true;
            t_day = day;
            FindAnswer();
            day = t_day;
            for(int j=i;j<i+T[i];j++)
                chk[j] = false;
            max_benefit -= P[i];
            day -= T[i];
            day+=1;
        }
    }
}

int main()
{
    ifstream input("input.txt");
    input >> N;
    // scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        // scanf("%d %d", &T[i], &P[i]);
        input >> T[i] >> P[i];
    }

    FindAnswer();

    printf("%d\n", ans);

    return 0;
}