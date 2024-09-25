#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long>>> adj(n+1);
    for(int i=0;i<m;i++){
      int a,b;
      long c;
      cin>>a>>b>>c;
      adj[a].push_back({b,c});
    }
    vector<long long> distance(n+1,2e18);
    vector<long long> freq(n+1,0);
    vector<int> minf(n+1,INT_MAX);
    vector<int> maxf(n+1,-1);
    minf[1]=maxf[1]=0;
    distance[1]=0;
    freq[1]=1;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int node=pq.top().second;
        long long cost= pq.top().first;
        pq.pop();
        if(cost>distance[node]) continue;
        for(auto t:adj[node]){
            int child= t.first;
            long wt= t.second;
            if(distance[child]>cost+wt){
                distance[child]=cost+wt;
                pq.push({distance[child],child});
                freq[child]=freq[node];
                minf[child]=minf[node]+1;
                maxf[child]=1+maxf[node];

            }else if(distance[child]==cost+wt){
                freq[child]=(freq[child]+freq[node])%1000000007;
                minf[child]=min(minf[child],1+minf[node]);
                maxf[child]=max(maxf[child],1+maxf[node]);
            }
        }

    }
    cout<<distance[n]<<" "<<freq[n]<<" "<<minf[n]<<" "<<maxf[n];
    return 0;

}