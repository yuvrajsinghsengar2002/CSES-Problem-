#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int> &visited,vector<vector<int>> &reverse){
    visited[i]=1;
    for(auto t:reverse[i]){
        if(visited[t]==0){
            dfs(t,visited,reverse);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> adj(n+1);
    // vector<vector<long long>> adj1(n+1,vector<long long>(n+1,2e18));
    vector<vector<int>> reverse(n+1);
    // vector<int> visited(n+1,0);
    for(int i=0;i<m;i++)
    {
        long long a,b,x;
        cin>>a>>b>>x;
        adj[a].push_back({b,-1*x});
        reverse[b].push_back(a);
    }
    vector<int> visited(n+1,0);
    dfs(n,visited,reverse);
    vector<long long> distance(n+1,2e18);
    distance[1]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            for(auto x:adj[j]){
                if(distance[j]!=2e18 ){
                    distance[x.first]=min(distance[x.first],distance[j]+x.second);
                }
            }
        }
    }
    long long minDist=distance[n];
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            if(distance[i]!=2e18){
               if(distance[i]+x.second<distance[x.first] && visited[x.first]==1){
                    cout<<-1<<endl;
                    return 0;
               }
            }
        }
    }

    
    cout<<distance[n]*-1<<endl;
    return 0;
}