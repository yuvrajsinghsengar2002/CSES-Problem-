#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<bool> &visitedEdges,vector<int> &eulerianCircuit){
    while(adj[node].size()>0){
        auto t=adj[node].back();
        adj[node].pop_back();
        int nextNode= t.first;
        int index= t.second;
        if(!visitedEdges[index]){
            visitedEdges[index]=true;
            dfs(nextNode,adj,visitedEdges,eulerianCircuit);

        }
        
    }
    eulerianCircuit.push_back(node);
}
int main(){
   int n,m;
   cin>>n>>m;
   vector<int> degree(n+1,0);
   vector<vector<pair<int,int>>> adj(n+1); 
   vector<bool> visitedEdges(m,false);
   for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       adj[a].push_back({b,i});
       adj[b].push_back({a,i});
       degree[a]++;
       degree[b]++;
   }
   for(int i=1;i<=n;i++){
       if(degree[i]%2==1){
           cout<<"IMPOSSIBLE"<<endl;
           return 0;
       }
   }
   vector<int> eulerianCircuit;
   int start=1;
   dfs(start,adj,visitedEdges,eulerianCircuit);
   if(eulerianCircuit.size()!=m+1){
       cout<<"IMPOSSIBLE"<<endl;
       return 0;
   }else{
       reverse(eulerianCircuit.begin(),eulerianCircuit.end());
       for(int i=0;i<eulerianCircuit.size();i++){
        cout<<eulerianCircuit[i]<<" ";
       }
       cout<<endl;
   }

   return 0;

}