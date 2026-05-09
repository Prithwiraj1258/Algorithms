#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005] = {false};
int parent[1000] = {-1};
vector<int> path;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    parent[src] =-1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
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

    int src, dis;
    cin >> src >> dis;
    bfs(src);
    int node=dis;
    while(node !=-1){
        path.push_back(node);
        node=parent[node];
    }
    reverse(path.begin(),path.end());
    for(int x:path){
        cout<<x<<" ";
    }
    return 0;
}