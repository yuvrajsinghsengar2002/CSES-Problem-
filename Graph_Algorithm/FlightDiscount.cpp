#include<bits/stdc++.h>
using namespace std;
void dijkastra(int n,vector<vector<pair<int,long long>>> &adj,int src,vector<long long> &distance){
    distance[src]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int node=pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(cost>distance[node]){
            continue;
        }
        else{
            for(auto t:adj[node]){
                int child=t.first;
                long long wt=t.second;
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
    vector<vector<pair<int,long long>>> edges(n+1),edgesReverse(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edgesReverse[b].push_back({a,c});   
    }
    
    vector<long long> distanceSourec(n+1,2e18),distanceDestination(n+1,2e18);
    dijkastra(n,edges,1,distanceSourec);
    dijkastra(n,edgesReverse,n,distanceDestination);
    long long ans=2e18;
    for(int i=1;i<=n;i++){
        for(auto t:edges[i]){   
            int u=i;
            int v=t.first;
            long long w=t.second;
            ans=min(ans,distanceSourec[u]+w/2+distanceDestination[v]);
        }
    }
    cout<<ans;
    return 0;
    
}