#include<bits/stdc++.h>
using namespace std;
void dijkastra(int n,vector<vector<pair<int,int>>> &adj,int src,vector<long long> &distance){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    distance[src]=0;
    pq.push({0,src});
    vector<int> included(n+1,0);
    while(!pq.empty()){
          int node=pq.top().second;
          long long cost=pq.top().first;
          pq.pop();
          if(cost>distance[node]) continue;
          if(included[node]!=1){
            included[node]=1;
            for(auto t:adj[node]){
                int child=t.first;
                int wt=t.second;
                if(distance[child]>cost+wt){
                    distance[child]=cost+wt;
                    pq.push({distance[child],child});
                }
            }
          }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long> distance(n+1,2e18);
    dijkastra(n,adj,1,distance);
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    return 0;
}