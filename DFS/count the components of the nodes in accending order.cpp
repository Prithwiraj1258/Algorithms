#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005] = {false};
vector<int>q;
int cnt=0;
void dfs(int src)
{
    vis[src] = true;
    cnt++;
    for (int child : v[src])
    {
        if (vis[child] == false)
            dfs(child);
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
    cin>>src;
    for (int i = 0; i < m; i++)
    {
        if (vis[i] == false)
        {
            cnt=0; 
            dfs(i);
            q.push_back(cnt);
        }
       
    }

    for (int i = q.size()-1; i>=0; i--)
    {
        cout<<q[i]<<" ";
    }

    return 0;
}