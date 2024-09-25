#include<bits/stdc++.h>
using namespace std;
int solution(int a,int b,int kmax,vector<vector<int>> &vec){
    for(int i=0;i<=kmax;i++){
        if(b&(1<<i)){
            a=vec[i][a];
        }
    }
    return a?a:-1;
} 

int main(){ 
    int n,q;
    cin>>n>>q;
    int kmax=ceil(log2(n));
    vector<vector<int>> vec(kmax+1,vector<int>(n+1,-1)); 

    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        vec[0][i]=a;
    }  
    for(int i=1;i<=kmax;i++){
        for(int j=1;j<=n;j++){
            vec[i][j]=vec[i-1][vec[i-1][j]];
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<solution(a,b,kmax,vec)<<"\n";
    }
return 0;
}

