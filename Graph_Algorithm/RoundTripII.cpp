#include<bits/stdc++.h>
using namespace std;
int cycleEndPoint;
int par;
bool isCycle;
bool dfs(int i,int p,vector<vector<int>> &adj,vector<int> &visited,vector<int> &rec,vector<int> &parent){
     visited[i]=1;
     rec[i]=1;
     parent[i]=p;
     for(auto t:adj[i]){
        if(visited[t]==0){
            if(dfs(t,i,adj,visited,rec,parent)){
                return true;
            }
        }else if(rec[t]==1 ){
                cycleEndPoint=t;
                par=i;
                isCycle=true;
                return true;
        }
        else{
            continue;
        }
     }
     rec[i]=0;
     return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> parent(n+1,-1);
    vector<int> visited(n+1,0);
    vector<int> rec(n+1,0);
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            if(dfs(i,-1,adj,visited,rec,parent)){
                break;
            }
        }
    }

    if(isCycle){
        vector<int> path;
        path.push_back(cycleEndPoint);
        while(par!=cycleEndPoint){
            path.push_back(par);
            par=parent[par];
        }
        path.push_back(cycleEndPoint);
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto t:path){
            cout<<t<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE"<<endl;   
    }

    return 0;
}