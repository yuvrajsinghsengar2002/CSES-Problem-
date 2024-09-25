#include<bits/stdc++.h>
using namespace std; 

int rec(int i,int n,int x,int arr[],vector<vector<int>> &dp){
    if(x==0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(i==n){
        return 0;
    }
    if(dp[x][i]!=-1){
        return dp[x][i];
    }
    int notTaken=rec(i+1,n,x,arr,dp);
    int taken=rec(i,n,x-arr[i],arr,dp);

    return dp[x][i]=(notTaken+taken)%1000000007;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(sum+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j-arr[i]>=0){
                dp[j]=(dp[j]+dp[j-arr[i]])%1000000007;
            }
        }
    }
    cout<<dp[sum];
}