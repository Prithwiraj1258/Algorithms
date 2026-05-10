#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[105] = {false};
int parent[105] = {-1};
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    for (int child : v[src])
    {
        if(vis[child]&& parent[src]!=child){
        cycle= true;
        }
        if (vis[child] == false){
            parent[child] = src;
                dfs(child);
    }
}
}
int main()
{
    int m, e;
    cin >> m >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cycle=false;
    for (int i = 0; i < m; i++)
    {
        if(!vis[i])
        dfs(i);
    }
    if (cycle)
        cout << "cycle detected";
    else
        cout << "Not Detected";
    return 0;
}