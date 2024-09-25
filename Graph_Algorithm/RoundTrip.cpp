#include<bits/stdc++.h>
using namespace std;
// void dfs(int i,int p,vector<vector<int>> &adj,vector<vector<int>> &visited,vector<int> &parent);
bool isCycle;
int cycleEndPoint;
int par;

bool dfs(int i,int p,vector<vector<int>> &adj,vector<int> &visited,vector<int> &parent){
    visited[i]=1;
    parent[i]=p;
    for(auto t:adj[i]){
        if(!visited[t]){
            if(dfs(t,i,adj,visited,parent)){
                return true;
            };
        }else if(t!=p){
            isCycle=true;
            cycleEndPoint=t;
            par=i;
            return true;
        }
    }
return false;
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>> adj(n+1);
vector<int> visited(n+1,0);
vector<int> parent(n+1,-1);
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
for(int i=1;i<=n;i++){
    if(visited[i]!=1){
     if(dfs(i,-1,adj,visited,parent)) break;
     }
}
vector<int> path;
if(isCycle){
    path.push_back(cycleEndPoint); 
    while(par!=cycleEndPoint){
        path.push_back(par);
        par=parent[par];
    }
    path.push_back(cycleEndPoint);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto t:path){
        cout<<t<<" ";
    }
}else{
    cout<<"IMPOSSIBLE"<<endl;
}
return 0;
}
