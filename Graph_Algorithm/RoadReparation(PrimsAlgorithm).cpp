#include<bits/stdc++.h>
using namespace std;
void prims(int n,int m,vector<vector<pair<int,long>>> adj){
    vector<bool> isMST(n+1,false);
    vector<int> parent(n+1,-1);
    vector<long> key(n+1,INT_MAX);
    key[1]=0;
    long res=0;
    priority_queue<pair<long , int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int node=pq.top().second;
        long wt=pq.top().first;
        pq.pop();
        if(isMST[node]) continue;
        res+=wt;
        isMST[node]=true;
        for(auto t:adj[node]){
               int child=t.first;
               long cost=t.second;
               if(!isMST[child]){
                   
                   pq.push({cost,child});
               }
        }
    }
    bool possible=true;
    for(int i=1;i<=n;i++){
        if(!isMST[i]){
            possible=false;
            break;
        }
    }

    if(possible){
        cout<<res<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<pair<int,long>>> adj(n+1);
   for(int i=0;i<m;i++){
     int a,b;
     long c;
     cin>>a>>b>>c;
     adj[a].push_back({b,c});
     adj[b].push_back({a,c});
   }
   prims(n,m,adj);
   return 0;
}