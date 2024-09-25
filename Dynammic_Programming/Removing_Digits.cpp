#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,INT_MAX-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int number=i;
        while(number>0){
            int last_digit=number%10;
            mini=min(mini,dp[i-last_digit]+1);
            number=number/10;
        }
        dp[i]=mini;
    }

    cout<<dp[n];
    return 0;
}