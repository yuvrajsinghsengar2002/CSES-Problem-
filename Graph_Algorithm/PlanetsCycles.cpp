#include<bits/stdc++.h>
using namespace std;
int steps;
queue<int> path;

void dfs(int i,vector<int>& pathLength,vector<bool> &visited,vector<int> &adj){
    path.push(i);
    if(visited[i]){
        steps+=pathLength[i];
        return;
    }
    steps++;
    visited[i]=true;
    dfs(adj[i],pathLength,visited,adj);
}
int main(){
    int n;
    cin>>n;
    vector<int> adj(n+1);
    for(int i=1;i<=n;i++){
        cin>>adj[i];
    }
    vector<bool> visited(n+1,false);
    vector<int> pathLength(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            steps=0;
            dfs(i,pathLength,visited,adj);
            int decrement=1;
            while(!path.empty()){
                if(path.front()==path.back()){
                    decrement=0;
                }
                pathLength[path.front()]=steps;
                steps-=decrement;
                path.pop();
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<pathLength[i]<<" ";
    }
    return 0;
}
