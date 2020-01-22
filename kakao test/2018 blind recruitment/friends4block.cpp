#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int,int> > find(int m, int n, vector<string> board)
{   
    vector<pair<int,int> > result;
    pair<int, int> p;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(board[i][j] == ' ' ) continue;
            if(board[i].substr(j,2) == board[i+1].substr(j,2) && board[i][j] == board[i][j+1]) 
            {
                p = make_pair(i,j);
                result.push_back(p);
            }
        }
    }
    return result;
}

vector<string> del(vector<string> board, vector<pair<int,int> > p)
{
    int row, col;
    for(int i=0;i<p.size();i++)
    {
        row = p[i].first;
        col = p[i].second;
        
        board[row][col] = ' ';
        board[row][col+1] = ' ';
        board[row+1][col] = ' ';
        board[row+1][col+1] = ' ';
    }
    return board;
}

vector<string> relocate(int m, int n, vector<string> board)
{
    for(int j=0;j<n;j++)
    {
        for(int i=m-1;i>1;i--)
        {
            int row = i-2;
            if(board[i][j] != ' ') continue;
            if(row<0) break;
            while(board[row][j] == ' ')
            {
                row--;
                if(row<1) break;
            }
            if(row<0) break;
            if(board[row][j] != ' '){
                board[i][j] = board[row][j];
                board[row][j] = ' ';
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int,int> > where;
    do{
        where.clear();   
        where = find(m, n, board);
        board = del(board, where);
        board = relocate(m, n, board);
    } while( where.size() != 0); 
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(board[i][j] == ' ') answer++;
    return answer;
}