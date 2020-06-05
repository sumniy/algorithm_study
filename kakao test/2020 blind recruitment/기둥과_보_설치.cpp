#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0 기둥 , 1 보
// 기둥
vector<vector<bool>> column(200, vector<bool>(200, false));
// 보
vector<vector<bool>> girder(200, vector<bool>(200, false));

bool check(int n, int x, int y, int kind)
{
    // 기둥
    if(kind == 0)
    {
        if(y==n) return false;

        if(y==0 || column[x + 1][y-1 + 1] == true || girder[x-1+1][y+1] == true || girder[x+1][y+1] == true) 
            return true;
        else return false;
    }
    // 보
    else if(kind == 1)
    {
        // 바닥에 보
        if(y==0 || x ==n) return false;

        if( column[x + 1][y-1 + 1] == true || column[x + 1 + 1][y-1 + 1] == true || (girder[x-1+1][y+1] == true && girder[x+1 +1][y+1] == true))
            return true;
        else return false;
    }
    return false;
}

void delete_answer_elem(vector<vector<int>>& answer, int x, int y, int kind)
{
    for(auto it = answer.begin();it!=answer.end();++it)
    {
        vector<int> elem = *it;
        if(elem[0] == x && elem[1] == y && elem[2] == kind)
        {
            answer.erase(it);
            return;
        }
    }
}

bool operator<(vector<int> a, vector<int> b)
{
    if(a[0] == b[0])
    {
        if(a[1] == b[1])
        {
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

void conduct(int x, int y, int kind, int cmd)
{
    if(kind == 0)
    {
        if(cmd == 1) column[x+1][y+1] = true;
        else column[x+1][y+1] = false;
    }
    else
    {
        if(cmd==1) girder[x+1][y+1] = true;
        else girder[x+1][y+1] = false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(auto& build_elem : build_frame)
    {
        int x = build_elem[0];  int y = build_elem[1]; int kind = build_elem[2]; int cmd = build_elem[3];
        
        // cmd == 0 삭제 // cmd == 1 설치
        if(cmd == 0)
        {
            delete_answer_elem(answer, x, y, kind);
            conduct(x, y, kind, cmd);
            for(auto& elem : answer)
            {
                if(!check(n, elem[0], elem[1], elem[2]))
                {
                    answer.push_back({x, y, kind});
                    conduct(x,y,kind, 1);
                    break;
                }
            }
        }
        else if(cmd == 1)
        {
            if(check(n, x, y, kind))
            {
                answer.push_back({x, y, kind});
                conduct(x,y,kind, cmd);
            }
            else continue;
        }
    }
    sort(answer.begin(), answer.end()); 
    
    return answer;
}