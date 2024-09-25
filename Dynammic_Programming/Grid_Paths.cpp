#include<bits/stdc++.h>
using namespace std;

int rec(int i,int j,vector<vector<char>> &grid,vector<vector<long>> &dp,int n){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    if(grid[i][j]=='*'){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    dp[i][j]=(rec(i+1,j,grid,dp,n)+rec(i,j+1,grid,dp,n))%1000000007;
    return dp[i][j];
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[n-1][n-1]=='*'){
         cout<<0;
         return 0;
    }
    vector<vector<long>> dp(n,vector<long>(n,0));
      
    dp[n-1][n-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(grid[i][j]=='*'){
                dp[i][j]=0;
            }
            else if(i==n-1 && j==n-1){
                dp[i][j]=1;
            }
            else if(i==n-1){
                dp[i][j]=dp[i][j+1];
            }
            else if(j==n-1){
                dp[i][j]=dp[i+1][j];
            }
            else{
                dp[i][j]=(dp[i+1][j]+dp[i][j+1])%1000000007;
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;

}