#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,vector<int> &visited,vector<vector<int>> &adj,int color )
{
   visited[i]=color;
   int  newcolor=color==1?2:1;
   for(auto t:adj[i])
   {
       if(visited[t]==0)
       {   
           
          if(!dfs(t,visited,adj,newcolor)){
            return false;
          }
       }else if(visited[t]==color){
        return false;
       }else{
        continue;
       }
   }
   return true;
}
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
    vector<int> visited(n+1,0);
    int color=1;
    for(int i=1;i<=n;i++)     
    {
        if(visited[i]==0){
            if(!dfs(i,visited,adj,color)){
               cout<<"IMPOSSIBLE"<<endl;
               return 0;
           }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<visited[i]<<" ";
    }
    
return 0;
}