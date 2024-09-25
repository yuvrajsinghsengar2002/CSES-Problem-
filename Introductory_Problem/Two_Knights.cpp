#include<bits/stdc++.h>
using namespace std;

long long getNumberOfKnights(long long n){
    long long ans=(n*n)*(n*n -1)/2 - 4*(n-1)*(n-2);
    return ans;
}
int main(){
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<getNumberOfKnights(i)<<endl;
    }
    
}