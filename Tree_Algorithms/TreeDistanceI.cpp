#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> firstChild,secondChild,child;

int dfs1(int i,int parent){
    for(auto to:adj[i]){
        if(to!=parent){
            dfs1(to,i);
            if(firstChild[i]<firstChild[to]+1){
                secondChild[i]=firstChild[i];
                firstChild[i]=firstChild[to]+1;
                child[i]=to;}
            else if(secondChild[i]<firstChild[to]+1){
                secondChild[i]=firstChild[to]+1;
            
            }    
        }            
    }
    return firstChild[i];
}

void dfs2(int i,int parent){
    for(auto to:adj[i]){
        if(to==parent){
            continue;
        }
        if(child[i]==to){
            if(firstChild[to]<secondChild[i]+1){
                secondChild[to]=firstChild[to];
                firstChild[to]=secondChild[i]+1;
                child[to]=i;
            }else{
                secondChild[to]=max(secondChild[to],secondChild[i]+1);
            }
        }
        else{
            secondChild[to]=firstChild[to];
            firstChild[to]=firstChild[i]+1;
            child[to]=i;
        }
        dfs2(to,i);
    }
}
int main(){
    int n;
    cin>>n;
    adj.resize(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    firstChild.resize(n+1,0);
    secondChild.resize(n+1,0);
    child.resize(n+1,0);
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<firstChild[i]<<" ";
    }
}


