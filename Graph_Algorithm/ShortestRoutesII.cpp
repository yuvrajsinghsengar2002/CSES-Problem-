#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> adj(n+1,vector<long long>(n+1,2e18));
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        adj[a][b]=min(c,adj[a][b]);
        adj[b][a]=min(c,adj[b][a]);
    }
    for(int i=1;i<=n;i++){
        adj[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(adj[a][b]==2e18){
            cout<<-1<<endl;
        }
        else{
            cout<<adj[a][b]<<endl;
        }
    }

    return 0;
}