#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
       int a;
       cin>>a;
       arr.push_back({a,i});
    }
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<j){
        if(arr[i].first+arr[j].first==x){
             cout<<arr[i].second+1<<" "<<arr[j].second+1;
             return 0;
        }else if(arr[i].first+arr[j].first>x){
            j--;
        }else{
            i++;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}