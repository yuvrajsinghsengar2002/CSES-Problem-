#include<bits/stdc++.h>
using namespace std;
void dfs1(int i,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &st){
    visited[i]=true;
    for(auto t:adj[i]){
        if(!visited[t]){
            dfs1(t,adj,visited,st);
        }
    }
    st.push(i);
}
void dfs2(int i,vector<vector<int>> &adjT,vector<bool> &visited){
    visited[i]=true;
    for(auto t:adjT[i]){
        if(!visited[t]){
            dfs2(t,adjT,visited);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1),adjT(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adjT[y].push_back(x);
    }
    // bool visited[n+1]={false};
    vector<bool> visited(n+1,false);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i,adj,visited,st);
        }   
    }

    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    int cnt=0,a,b;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        if(!visited[t]){
            cnt++;
            if(cnt==1){
               a=t;
            }
            if(cnt==2){
                b=t;
            }

            dfs2(t,adjT,visited);
        }
    }
    if(cnt==1){
        cout<<"YES";
        return 0;
    }
    cout<<"NO"<<endl;
    cout<<b<<" "<<a;
    return 0;
}