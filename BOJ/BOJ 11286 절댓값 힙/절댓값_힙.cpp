#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> positive;
    priority_queue<int, vector<int>, less<int>> negative;

    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int num;
        cin >> num;
        if(num == 0)
        {
            if(positive.empty() && negative.empty())
            {
                cout<<0<<endl;
                continue;
            }
            else if(positive.empty() && !negative.empty())
            {
                cout<<negative.top()<<endl;
                negative.pop();
                continue;
            }
            else if(!positive.empty() && negative.empty())
            {
                cout<<positive.top()<<endl;
                positive.pop();
                continue;
            }

            int p_top = positive.top();
            int n_top = abs(negative.top());

            if(p_top < n_top)
            {
                cout<<positive.top()<<endl;
                positive.pop();
            }
            else
            {
                cout<<negative.top()<<endl;
                negative.pop();
            }
        }
        else
        {
            if(num > 0)
                positive.push(num);
            else
                negative.push(num);
        }
        
    }
    return 0;
}