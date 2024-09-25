#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>& visited,vector<vector<int>>& adj){
    visited[i]=1;
    for(auto t:adj[i]){
        if(visited[t]==0){
            dfs(t,visited,adj);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> visited(n+1,0);
    vector<int> startingpoints;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            startingpoints.push_back(i);
            dfs(i,visited,adj);
        }
    }

    cout<<startingpoints.size()-1<<endl;
    for(int i=0;i<startingpoints.size()-1;i++){
        cout<<startingpoints[i]<<" "<<startingpoints[i+1]<<endl;
    }
    return 0;
}