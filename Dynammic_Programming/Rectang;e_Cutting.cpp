#include<bits/stdc++.h>
using namespace std;
int rec(int a, int b,vector<vector<int>> &dp){
    if(a==b){
        return 0;
    }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    int mini=INT_MAX;
    for(int i=1;i<a/2+1;i++){
        mini=min(mini,1+rec(i,b,dp)+rec(a-i,b,dp));
    }
    for(int i=1;i<b/2+1;i++){
        mini=min(mini,1+rec(a,i,dp)+rec(a,b-i,dp));
    }
    return dp[a][b]=mini;
}
int main()
{
 int a,b;
 cin>>a;
 cin>>b;
 vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
 cout<<rec(a,b,dp);
 return 0;  
}