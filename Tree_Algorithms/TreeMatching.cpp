#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp,adj;

void solve(int i ,int parent){
    for(int k=0;k<adj[i].size();k++){
        if(adj[i][k]!=parent){
            solve(adj[i][k],i);
            dp[i][0]=dp[i][0]+max(dp[adj[i][k]][0],dp[adj[i][k]][1]);
        }
        for(int k=0;k<adj[i].size();k++){
            if(adj[i][k]!=parent){
                dp[i][1]=max(dp[i][1],(1+dp[adj[i][k]][0]+dp[i][0]-max(dp[adj[i][k]][0],dp[adj[i][k]][1])));
            }
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
    dp.resize(n+1,vector<int>(2,0));
    solve(1,0);
    cout<<max(dp[1][0],dp[1][1]);
}