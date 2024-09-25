#include <bits/stdc++.h>
using namespace std;

int calc(int i,vector<vector<int>> &adj,vector<int> &subtree){
    if(adj[i].size()==0){
        return 1;
    }
    
    int ans=0;
    for(int j=0;j<adj[i].size();j++){
        ans=ans+calc(adj[i][j],adj,subtree);
    }
   
    subtree[i]=ans;
    return subtree[i]+1;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    vector<int> subtree(n+1,0);
    calc(1,adj,subtree);
    for(int i=1;i<=n;i++){
       cout<<subtree[i]<<" ";
    }
    return 0;
}
