#include<bits/stdc++.h>
using namespace std;
class EulrianPathInDirectedGraph{
private:
    int nodes,edges;
    vector<vector<pair<int,int>>> adj;
    vector<bool> visitedEdges;
    vector<int> degrees;
    vector<int> eularianPath;
    int  firstChild;
    int  lastChild;

public:
    EulrianPathInDirectedGraph(int n,int m){
      adj.resize(n+1);
      visitedEdges.resize(m);
      degrees.resize(n+1); 
      nodes=n;
      edges=m;
      firstChild=-1;
      lastChild=-1;

    }
    
    void addEdge(int parent,int child,int index){
         adj[parent].push_back({child,index});
         degrees[parent]++;
         degrees[child]--;
    }
    void dfs(int node){
        while(!adj[node].empty()){
               auto t= adj[node].back();
               adj[node].pop_back();
               int nextNode=t.first;
               int index=t.second;
               if(visitedEdges[index]){
                continue;
               }
               visitedEdges[index]=true;
               dfs(nextNode);
        }

        eularianPath.push_back(node);
    }

    void Solve(){

        for(int i=1;i<=nodes;i++){
            if(abs(degrees[i])>1){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }else if(degrees[i]==-1){
                 if(lastChild==-1){
                    lastChild=i;
                 }else{
                    cout<<"IMPOSSIBLE";
                    return;
                 }
            }else if(degrees[i]==1){
                 if(firstChild==-1){
                      firstChild=i;
                 }else{
                    cout<<"IMPOSSIBLE";
                    return;
                 }
            }else continue;
        }

        if(firstChild!=1 || lastChild!=nodes ){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        dfs(1);
        if(eularianPath.size()!= edges+1){
            cout<<"IMPOSSIBLE";
            return;
        }else{
            reverse(eularianPath.begin(),eularianPath.end());
            for(auto node : eularianPath){
                cout<<node << " ";
            }
            cout<<endl;
            return;
        }
    }

};

int main(){
    int n,m;
    cin>>n>>m;
    EulrianPathInDirectedGraph e(n,m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e.addEdge(a,b,i);
    }
    e.Solve();
    return 0;
}