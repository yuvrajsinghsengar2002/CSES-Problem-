#include<bits/stdc++.h>
using namespace std;

int rec(int i,int j, string &a,string &b,vector<vector<int>> &dp){
if(i<0 && j<0){
    return 0;
}
if(i<0){
    return j+1;
}
if(j<0){
    return i+1;
}

if(dp[i][j]!=-1){
    return dp[i][j];
}
if(a[i]==b[j]){
    return dp[i][j]=rec(i-1,j-1,a,b,dp);
}
else{
    int deleted=rec(i-1,j,a,b,dp);
    int replaced=rec(i-1,j-1,a,b,dp);
    int added=rec(i,j-1,a,b,dp);
    return dp[i][j]=1+min(deleted,min(replaced,added));
}


}
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<rec(n-1,m-1,a,b,dp);
    return 0;   
}