#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int cnt=0;
vector<int> c(int src)
{
         vector<int>c; 
        for (int child : v[src])
        { 
                cnt++;
                c.push_back(child);   
        }  
        return c;
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
    int t;
    cin>>t;
    while(t--){
        int qu;
        cin>>qu;
        vector<int>s=c(qu);
        if(s.size()==0){
            cout<<"-1";
        }
        sort(s.begin(),s.end(),greater<int>());
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}