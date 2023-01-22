#include <iostream>
using namespace std;
#define I INT_MAX
void prims(int cost[8][8])
{
    int n = 7, minEl = I;
    int parent[n + 1]{ I };          //To check edge with min weight
    int mst[2][n - 1];               //To store min Spanning tree
    int i, j, u, v, k;
    for (i = 1; i <= n; i++)          //To select edge with minimum weight
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < minEl)
            {
                minEl = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    mst[0][0] = u;          //Stored first
    mst[1][0] = v;          //edge pair
    parent[u] = parent[v] = 0;
    for (i = 1; i <= n; i++)             //To check for the parent vertex with min weight for first case
    {
        if (cost[i][u] < cost[i][v])
            parent[i] = u;
        else
            parent[i] = v;
    }

    for (i = 1; i < n - 1; i++)
    {
        int Min = I;
        for (j = 1; j <= n; j++)             //To find edge with min weight fromm parent array
        {
            if (parent[j] != 0 && cost[j][parent[j]]< Min)
            {
                k = j;
                Min = cost[j][parent[j]];
            }
        }
        mst[0][i] = k;
        mst[1][i] = parent[k];
        parent[k] = 0;
        for (j = 1; j <= n; j++)            //To change the next vertex if wt is not min; Updating new value of k for new vertex
        {
            if (parent[j] != 0 && cost[j][k] < cost[j][parent[j]])
            {
                parent[j] = k;
            }
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < n - 1; i++)          //Printing min Spanning tree
    {
        cout << mst[0][i] << " " << mst[1][i] << endl;
    }
}
int main()
{
    int cost[][8] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I}
    };
    prims(cost);
}
