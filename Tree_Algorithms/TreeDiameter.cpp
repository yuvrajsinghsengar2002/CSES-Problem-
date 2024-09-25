#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<vector<int>> adj;
int ans;
int diameter(int i,int parent){
int maxi1=0,maxi2=0;

   for(auto to: adj[i]){
       if(to!=parent){
        diameter(to,i);
        dp[i]=max(dp[i],dp[to]+1);
        if(dp[to]+1>maxi1){
            maxi2=maxi1;
            maxi1=dp[to]+1;
        }
        else if(dp[to]+1>maxi2){
            maxi2=dp[to]+1;
        }
       }
   }
   ans=max(ans,maxi1+maxi2);
   return maxi1;
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
    ans=0;
    dp.resize(n+1,0);
    diameter(1,0);
    cout<<ans;
}
