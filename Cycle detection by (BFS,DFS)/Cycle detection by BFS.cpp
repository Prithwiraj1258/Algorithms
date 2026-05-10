#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005] = {false};
bool cycle;
int parent[105]={-1};
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {     
        int par = q.front();
        q.pop();
        
        for (int child : v[par])
        {
            if(vis[child] && parent[par]!=child)
            cycle=true;
            if (vis[child] == false)
            {
              
                vis[child] = true ;
                parent[child]=par;
                q.push(child);
            }
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i])
        bfs(i);
    }
    if(cycle)
    cout<<"cycle detected";
    else
    cout<<"Not Detected";
    return 0;
}