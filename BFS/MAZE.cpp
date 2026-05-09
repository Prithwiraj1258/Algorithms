#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[105][105] = {false};
char grid[105][105];
vector<pair<int, int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
char level[105][105];
int m, n;
bool valid(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) == true && !vis[ci][cj] && grid[ci][cj] == '-' || grid[ci][cj] =='D')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
               if(grid[ci][cj]= '-')
               grid[ci][cj]='X';
            }
        }
    }
}
int main()
{

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'R')
            {
                bfs(i,j);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< grid[i][j];
        }
        cout<<endl;
    }
            return 0;
        }
