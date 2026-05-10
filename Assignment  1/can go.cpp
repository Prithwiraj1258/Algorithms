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
            if (valid(ci, cj) == true && !vis[ci][cj] && (grid[ci][cj] == '-'||grid[ci][cj]=='B'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
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
    int si,sj,di,dj;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if(grid[i][j]=='B'){
                di=i;
                dj=j;
            }
        }
    }
        valid(si,sj);
        bfs(si,sj);
        if(vis[di][dj])
        cout<<"YES";
        else
        cout<<"NO";
        return 0;
    }