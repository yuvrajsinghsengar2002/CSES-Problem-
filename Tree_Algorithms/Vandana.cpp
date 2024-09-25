#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> graph; 
vector<long long> weights; 
vector<int> parent;


void dfs(int node,int par){
    parent[node]=par;
   weights[node]+=node;
   for(auto it: graph[node]){
     if(it!=par){
        dfs(it,node);
        weights[node]+=weights[it];
    }
   }
}


long long MinDiff(int n,int A[],int B[]){
    graph.resize(n+1);
    weights.resize(n+1,0);
    parent.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int u=A[i];
        int v=B[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
        
    }
    dfs(1,-1);
    long long ans=LONG_LONG_MAX;
    long long totalSum=(n*(n+1))/2;
    for(int i=1;i<=n;i++){
        long long sum1=weights[i];
        long long sum2=totalSum-weights[i];
        long long diff=abs(sum1-sum2);
        ans=min(ans,diff);
    }
    return ans;
}






int main(){
    int n=7;
    int A[]={1,2,3,1,5,6};
    int B[]={2,3,4,5,6,7};
    cout<<MinDiff(n,A,B);
    return 0;
}