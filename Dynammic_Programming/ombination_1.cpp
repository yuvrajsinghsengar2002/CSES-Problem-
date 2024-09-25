#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    int arr[n];
    cin>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(x+1,-1);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        long  sum=0;
        for(int j=0;j<n;j++){
            if(i-arr[j]>=0){
                if(dp[i-arr[j]]!=-1){
                    sum=(sum+dp[i-arr[j]])%1000000007;
                }
            }
        }  
        if(sum!=0){
            dp[i]=sum;
        }      
    } 
    if(dp[x]==-1){
        cout<<0<<endl;
        return 0;
    }
    cout<<dp[x]<<endl;  
     return 0;
}