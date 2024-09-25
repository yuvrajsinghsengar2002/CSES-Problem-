#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<long>> dp(m+2,vector<long>(n+1,0));
    if(arr[0]==0){
        for(int i=1;i<=m;i++){
            dp[i][1]=1;
        }
    }else{
         dp[arr[0]][1]=1;
    }
    for(int j=2;j<=n;j++){
          if(arr[j-1]!=0){
            dp[arr[j-1]][j]=(dp[arr[j-1]-1][j-1]+dp[arr[j-1]][j-1]+dp[arr[j-1]+1][j-1])%1000000007;
          }
          else{
            for(int i=1;i<=m;i++){
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1]+dp[i+1][j-1])%1000000007;
            }
          }
    }
    long  ans=0;
    for(int i=1;i<=m;i++)
    {
        ans=(ans+dp[i][n])%1000000007;
    }   
    cout<<ans;
    return 0;
}