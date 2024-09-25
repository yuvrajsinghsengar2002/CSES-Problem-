#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long >>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long> distance(n+1,0);
    vector<int> relaxant(n+1,0);
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            for(auto t:adj[j]){
                int child=t.first;
                int wt=t.second;
                if(distance[child]>distance[j]+wt){
                    distance[child]=distance[j]+wt;
                    relaxant[child]=j;
                }
            }
        }
    }
    int x=-1;
    for(int j=1;j<=n;j++){
            for(auto t:adj[j]){
                int child=t.first;
                int wt=t.second;
                if(distance[child]>distance[j]+wt){
                    distance[child]=distance[j]+wt;
                    relaxant[child]=j;
                    x=child;
                }
            }
        }
    if(x==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        x=relaxant[x];
    }
    vector<int> ans;
    ans.push_back(x);
    int initial=x;
    x=relaxant[x];
    while(x!=initial){
        ans.push_back(x);
        x=relaxant[x];
    }
    ans.push_back(x);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}