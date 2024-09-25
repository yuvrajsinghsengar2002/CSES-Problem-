#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto t:adj[i]){
            indegree[t]++;
        }
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto t:adj[u]){
            indegree[t]--;
            if(indegree[t]==0 && t!=1){
                q.push(t);
            }
        }
   }
vector<int> distance(n+1,0);
   distance[1]=1;
   q.push(1);
   while(!q.empty()){
       int u=q.front();
       q.pop();
       for(auto t:adj[u]){
           distance[t]=(distance[t]+distance[u])%mod;
           indegree[t]--;
           if(indegree[t]==0){
            q.push(t);
           }
       }
   }
   
   cout<<distance[n]<<endl;
   return 0;
    

}