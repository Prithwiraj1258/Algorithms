#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[105][105] = {false};

vector<pair<int, int>> d = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {2, 1}};
int level[105][105];
int m, n;
bool valid(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >=n)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) == true && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> m >> n;
        memset(vis, 0, sizeof(vis));
        memset(level,0,sizeof(level));
        int si, sj, qi, qj;
        cin >> si >> sj >> qi >> qj;
        bfs(si, sj);
        if (!vis[qi][qj])
        {
            cout << -1 << endl;
        }
        else
        {
            cout << level[qi][qj] << endl;
        }
    }
    return 0;
}