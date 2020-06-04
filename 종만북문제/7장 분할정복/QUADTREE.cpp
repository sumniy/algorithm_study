#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

string reverse_tree(string::iterator& it)
{
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w')
        return string(1, head);
    else 
    {
        string LU = reverse_tree(it);
        string RU = reverse_tree(it);
        string LD = reverse_tree(it);
        string RD = reverse_tree(it);
        return 'x' + LD + RD + LU + RU;
    }
}

int main()
{
    freopen("QUADTREE_input.txt", "r", stdin);

    int C;
    cin >> C;

    for (int tc = 0; tc < C; ++tc)
    {
        string compressed_tree;
        cin >> compressed_tree;

        if (compressed_tree.size() == 1)
            cout << compressed_tree << endl;

        string::iterator it = compressed_tree.begin();

        string answer = reverse_tree(it);

        cout << answer << endl;
    }
}