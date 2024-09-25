#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> reachedFrom(n+1,-1);
    vector<int> visited(n+1,-1);
    visited[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int child:adj[node]){
            if(visited[child]==-1){
                visited[child]=1;
                q.push(child);
                reachedFrom[child]=node;
            }
        }
    }
    if(reachedFrom[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    int cuur_node=n;
    while(cuur_node!=1){
        path.push_back(cuur_node);
        cuur_node=reachedFrom[cuur_node];
    
    }
    path.push_back(1);
    cout<<path.size()<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
}