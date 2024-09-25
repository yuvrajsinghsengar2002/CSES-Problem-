#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,long>>> adj(n+1); 
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<long>> distance(n+1,vector<long>(k,2e18));
    distance[1][0]=0;
    priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int node=pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(cost>distance[node][k-1]){continue;}
        for(auto t:adj[node]){
            int child=t.first;
            long long wt=t.second;
            if(distance[child][k-1]>cost+wt){
                distance[child][k-1]=cost+wt;
                pq.push({distance[child][k-1],child});
                sort(distance[child].begin(),distance[child].end());
            }
        }
    } 

    for(int i=0;i<k;i++){
        cout<<distance[n][i]<<" ";
    }  
return 0;
} 