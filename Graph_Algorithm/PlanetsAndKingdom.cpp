#include<bits/stdc++.h>
using namespace std;
void dfs1(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> &st){
    visited[i]=1;
    for(auto t:adj[i]){
        if(!visited[t]){
            dfs1(t,adj,visited,st);
        }
    }
    st.push(i);
}

void dfs2(int i,vector<vector<int>> &adj,vector<int> &kingdom,int k){
    kingdom[i]=k;
    for(auto t:adj[i]){
        if(!kingdom[t]){
            dfs2(t,adj,kingdom,k);
        } 
    }       
}
int main(){
    int  n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> reverse(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        reverse[b].push_back(a);
    }
    vector<int> visited(n+1,0);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i,adj,visited,st);
        }
    }
    vector<int> kingdom(n+1,0);
    int k=1;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!kingdom[top]){
            dfs2(top,reverse,kingdom,k);
            k++;
        }
    }
    cout<<k-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<kingdom[i]<<" ";
    }

    return 0;
}