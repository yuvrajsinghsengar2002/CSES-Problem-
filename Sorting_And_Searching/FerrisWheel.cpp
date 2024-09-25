#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    sort(wt,wt+n);
    int i=0,j=n-1;
    int pairs=0;
    while(i<j){
        if(wt[i]+wt[j]<=x){
            pairs++;
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    cout<<pairs+(n-2*pairs)<<endl;
}