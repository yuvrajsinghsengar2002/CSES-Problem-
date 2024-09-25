#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<vector<long long>> dp(1000000+1,vector<long long>(2,0));
        dp[1][0]=1;
        dp[1][1]=1;
        for(int i=2;i<=1000000;i++){
            dp[i][0]=(dp[i-1][1]+dp[i-1][0]*4)%1000000007;
            dp[i][1]=(dp[i-1][0]+dp[i-1][1]*2)%1000000007;

        }
    while(t>0){
        int n; 
        cin>>n;
        
        

        cout<<(dp[n][0]+dp[n][1])%1000000007<<endl;
        t--;
    }
  return 0;
}