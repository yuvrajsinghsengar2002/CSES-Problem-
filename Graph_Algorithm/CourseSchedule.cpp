#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,vector<int> &visited,vector<vector<int>> &adj,vector<int> &rec,stack<int> &st){

   visited[i]=1;
   rec[i]=1;
   for(auto t: adj[i]){
       if(visited[t]==0){
        if(dfs(t,visited,adj,rec,st)){
            return true;
        }
       }else if(rec[t]==1){
            return true;
        }else{
            continue;
        }
   }
   rec[i]=0;
   st.push(i);
   return false;   
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    vector<int> visited(n+1,0);
    vector<int> rec(n+1,0);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            if(dfs(i,visited,adj,rec,st)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }else{
                continue;
            }
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } 
    return 0;
}