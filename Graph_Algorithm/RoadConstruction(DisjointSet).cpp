#include<bits/stdc++.h>
using namespace std;
class DSU{
 vector<int> parent,size;
 int largestComponent;
 int numberOfComponents;
 public:   
 DSU (int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    largestComponent=1;
    numberOfComponents=n;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
 }

 int findParent(int node){
    if(parent[node]==node){
           return node;
    }
    return parent[node]=findParent(parent[node]);
 }

 pair<int,int> unionBySize(int u,int v){
    int pl_u=findParent(u);
    int pl_v=findParent(v);
    if(pl_u==pl_v){
         return {largestComponent,numberOfComponents};
    }
    if(size[pl_u]<size[pl_v]){
        parent[pl_u]=pl_v;
        size[pl_v]+=size[pl_u];
        largestComponent=max(largestComponent,size[pl_v]);
        numberOfComponents--;
        return {largestComponent,numberOfComponents};
    }else{
        parent[pl_v]=pl_u;
        size[pl_u]+=size[pl_v];
        largestComponent=max(largestComponent,size[pl_u]);
        numberOfComponents--;
        return {largestComponent,numberOfComponents};
    }

 }

};
int main(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        auto p=dsu.unionBySize(u,v);
        cout<<p.second<<" "<<p.first<<endl;
    }
  return 0;
}