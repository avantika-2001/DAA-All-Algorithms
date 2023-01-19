#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void bfs(int a[][7], int start, int n)
{
    vector<bool>visited;
    visited.resize(n, false);
    queue<int>q;
    cout << start << endl;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int j=q.pop();
        for (int i = 1; i < n; i++)
        {
            if (visited[i] != true && a[j][i] == 1)
            {
                cout << i << endl;
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    int G[7][7] = { {0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0} };
    bfs(G, 4, 7);

    return 0;
}
