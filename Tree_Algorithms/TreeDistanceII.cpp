#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> children;
vector<long> dist;
void dfs1(long i,long parent){
    for(auto to:adj[i]){
        if(to!=parent){
           dfs1(to,i);
           dist[i]=(dist[i]+dist[to]+children[to]+1);
           children[i]=children[to]+1+children[i];
        }
    }
}

void dfs2(long i,long parent){
    for(auto to:adj[i]){
        if(to!=parent){
           long d= dist[i]-(dist[to]+children[to]+1);
           long c=children[i]-(children[to]+1);
           dist[to]=(dist[to]+d+c+1);
           children[to]=children[to]+c+1;
           dfs2(to,i);

        }
    }
}
int main(){
int n; 
cin>>n;
adj.resize(n+1,vector<int>());
for(int i=0;i<n-1;i++){
   int a,b;
   cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(a);
}
children.resize(n+1,0);
dist.resize(n+1,0);

dfs1(1,0);
dfs2(1,0);

for(int i=1;i<=n;i++){
    cout<<dist[i]<<" ";
}

}