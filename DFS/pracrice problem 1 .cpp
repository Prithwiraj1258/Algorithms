#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005] = {false};
int cnt=0;
void dfs(int src)
{
    vis[src] = true;
    cnt++;
    for (int child : v[src])
    {
        if (vis[child] == false){
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
    int src;
    cin >> src;
    dfs(src);
    cout<<cnt;
    return 0;
}