#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[105][105] = {false};
char grid[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int m, n;
bool valid(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && grid[ci][cj]=='.')
            dfs(ci, cj);
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
    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);
    int x,y;
    cin>>x>>y;
    if(vis[x][y])
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}