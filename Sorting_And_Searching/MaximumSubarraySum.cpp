#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x); 
    }
    long long ans=-1e10;
    long long curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        ans=max(ans,curr_sum);
        if(curr_sum<0){
            curr_sum=0;
        }
    } 
    cout<<ans;

    return 0;
}