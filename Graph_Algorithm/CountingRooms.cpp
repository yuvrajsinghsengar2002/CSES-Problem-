#include<bits/stdc++.h>
using namespace std;
vector<int> dirx={0,0,1,-1};
vector<int> diry={1,-1,0,0};
void dfs(int x,int y,vector<vector<char>> &floor,vector<vector<int>> &vis,int n,int m){
      vis[x][y]=1;
      for(int i=0;i<=3;i++){
        int newx=x+dirx[i];
        int newy=y+diry[i];
        if(newx<0 || newx>=n ||newy<0 || newy>=m){
            continue;
        }
        else if(vis[newx][newy]==0 && floor[newx][newy]=='.'){
             dfs(newx,newy,floor,vis,n,m);
        }
      }

}

int main(){
int n,m;
cin>>n>>m;
vector<vector<char>> floor(n,vector<char>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>floor[i][j];
    }
}
vector<vector<int>> vis(n,vector<int>(m,0));
int count=0;
for(int i=0;i<n;i++){   
    for(int j=0;j<m;j++){   
        if(floor[i][j]=='.' && vis[i][j]==0){
            
            dfs(i,j,floor,vis,n,m);
            
                count++;
                           
 
        }
    }

}
cout<<count;
return 0;
}