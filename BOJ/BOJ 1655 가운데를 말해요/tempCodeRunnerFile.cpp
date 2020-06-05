#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, less<int>> left_pq;
    priority_queue<int, vector<int>, greater<int>> right_pq;

    for(int i=0;i<N;i++)
    {
        int num;
        cin >> num;

        int left_pq_size = left_pq.size();
        int right_pq_size = right_pq.size();

        if(left_pq_size == right_pq_size)
        {
            left_pq.push(num);
            cout<<left_pq.top()<<endl;
        }
        else
        {
            right_pq.push(num);
        }

        if(left_pq.top() > right_pq.top())
        {
            int left_top = left_pq.top();
            int right_top = right_pq.top();
            left_pq.pop();
            right_pq.pop();

            left_pq.push(right_top);
            right_pq.push(left_top);
        }

        cout<<left_pq.top()<<endl;
    }
    return 0;
}