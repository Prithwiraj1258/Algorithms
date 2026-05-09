#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005] = {false};
int level[1000]={-1};
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src]=0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child]=level[par]+1;
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
    // bfs(src);
    // for(int i=0;i<n;i++){
    //     cout<<i<<"->"<<level[i]<<endl;
    // }
    cout<<level[dis]<<endl;

    return 0;
}