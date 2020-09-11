#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    vector<int> save(dist);
    sort(dist.begin(), dist.end());
    deque<int> weak_point(weak.begin(), weak.end());
    int weak_size = weak.size();
    int min = 1001;

    for (int i = 0; i < n; i++)
    {
        do
        {
            int weak_index = 0;
            int cnt = 0;
            for (int distance : dist)
            {
                cnt++;
                int end = weak_point[weak_index] + distance;

                while (weak_index++ < weak_size && weak_point[weak_index] <= end){};

                if (weak_index >= weak_size)
                    break;
            }
            if (weak_index < weak_size)
                cnt = 1001;
            else if (min > cnt)
                min = cnt;
        } while (next_permutation(dist.begin(), dist.end()));
        dist = save;

        weak_point.push_back(weak_point.front()+n);
        weak_point.pop_front();
    }

    if (min == 1001) min = -1;
    return min;
}