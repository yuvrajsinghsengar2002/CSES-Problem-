#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int coins[n];
    int amount;
    cin>>amount;
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    vector<int> dp(amount+1,-1); 
    dp[0]=0;
    for(int i=1;i<=amount;i++)
    {   int sum=INT_MAX;
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0)
            {   
                if(dp[i-coins[j]]!=-1)
                sum=min(sum,dp[i-coins[j]]+1);
            }
        }
        if(sum!=INT_MAX){
            dp[i]=sum;
        }
    }
    cout<<dp[amount];
    return 0;
    
    }