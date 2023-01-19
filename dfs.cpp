#include <iostream>
#include <vector>
using namespace std;
void dfs(int G[][7], int start, int n)
{
    static bool visited[7] = {false};
    if (visited[start] == false)
    {
        cout << start << endl;
        visited[start] = true;
        for (int v = 1; v < n; v++)
        {
            if (visited[v] != true && G[start][v] == 1)
            {
                dfs(G, v, n);
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
    dfs(G, 4, 7);
}
