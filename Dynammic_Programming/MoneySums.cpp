#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j>=a[i-1])
            {
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    vector<int> possible;
    for(int i=1;i<=sum;i++){
        if(dp[n][i]){
            possible.push_back(i);
        }
    }
    cout<<possible.size()<<endl;
    for(int i=0;i<possible.size();i++)
    {
        cout<<possible[i]<<" ";
    }
    return 0;
}