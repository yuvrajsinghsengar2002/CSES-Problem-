#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> starting(n+1);
    vector<pair<int,int>> departure(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        starting[i]=a;
        departure[i]={b,i};
    }

    sort(departure.begin(),departure.end());
    int currEndingTime=departure[0].first;
    int ans=1;
    for(int i=1;i<n;i++){
        int movie=departure[i].second;
        if(starting[movie]>=currEndingTime){
            currEndingTime=departure[i].first;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}