#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,0});
        arr.push_back({b,1});
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i].second==0){
            cnt++;
        }
        else{
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;

}