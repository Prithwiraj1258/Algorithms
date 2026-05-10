#include <bits/stdc++.h>
using namespace std;
bool vis[105][105] = {false};
char grid[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int level[105][105];
int m, n;
int cnt = 0;
vector<int>apr;
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
            if (valid(ci, cj) == true && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                cnt++;
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
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt=1;
                bfs(i, j);
                apr.push_back(cnt);
            }
        }
    }
    if(apr.empty()==true){
        cout<<'0';
    }
   sort (apr.begin(),apr.end());
   for(int i=0;i<apr.size();i++){
   cout<<apr[i]<<" ";
   }
    return 0;
}