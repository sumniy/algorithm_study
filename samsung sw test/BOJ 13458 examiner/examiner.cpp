#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

int A[1000001];
int N, B, C;
long long answer;

int main()
{
    answer = 0;
    ifstream input("input.txt");

    scanf("%d", &N);
    // input >> N;

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    // input >> A[i];

    // input>> B >> C;
    scanf("%d %d", &B, &C);
    answer += N;

    for (int i = 0; i < N; i++)
    {
        A[i] -= B;
        if (A[i] > 0)
        {
            if (A[i] % C != 0)
            {
                answer += A[i] / C + 1;
            }
            else
            {
                answer += A[i] / C;
            }
        }
    }

    printf("%lld", answer);

    return 0;
}