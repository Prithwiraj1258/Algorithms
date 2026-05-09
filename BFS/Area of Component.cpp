#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[105][105] = {false};
char grid[105][105];
vector<int>k;
int node;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int m, n;
bool valid(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
    return true;
}
void dfs(int si, int sj,int &node)
{
    vis[si][sj] = true;
    node++;
    for (int i = 0; i < 4; i++)
    {
        
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && grid[ci][cj]=='.')
            dfs(ci, cj,node);
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
  int cnt=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]=='.'&& !vis[i][j]){
                node=0;
                dfs(i,j,node);
                k.push_back(node);
            }
        }
    }
    if (k.empty())
    {
        cout << -1;
    }
    else{
    int mn=k[0];
    for(int i=1;i<k.size();i++){
        if(k[i]<mn){
            mn=k[i];
        }
    }
    cout<<mn;
}
            return 0;
        }