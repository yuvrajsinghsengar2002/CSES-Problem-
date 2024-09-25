#include<bits/stdc++.h>
using namespace std;

int rec(int i,int n,int sum,vector<int> &prices,vector<int> &pages,vector<vector<int>> &dp){
    if(i<=0){
        return 0;
    }
    int taken=0;
    int notTaken=0;
    if(dp[i][sum]!=-1){
        return dp[i][sum];;
    }
    if(prices[i-1]<=sum){
         taken=(rec(i-1,n,sum-prices[i-1],prices,pages,dp)+pages[i-1])%1000000007;
    }
    notTaken=rec(i-1,n,sum,prices,pages,dp);
    return dp[i][sum]=max(taken,notTaken);
}
int main(){
    int n;
    int sum;
    cin>>n>>sum;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=sum;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            int taken=0;
            int notTaken=0;
            if(prices[i-1]<=j){
                taken=pages[i-1]+dp[i-1][j-prices[i-1]];
            }
            notTaken=dp[i-1][j];
            dp[i][j]=max(taken,notTaken);
        }
    }
    cout<<dp[n][sum];
    

}