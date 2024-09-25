#include<bits/stdc++.h>
using namespace std;
const int p=31;
const int m=1e9+9;
vector<long> power;
vector<long> hashArray;
long gethashArray(int l,int r){
    long h=(hashArray[r+1]-(hashArray[l]*power[r-l+1])%m)%m;
    return h<0?h+m:h;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    power.resize(n+1,1);
    for(int i=1;i<n;i++){
        power[i]=(power[i-1]*p)%m;
    }

 hashArray.assign(n+2,0);
    for(int i=1;i<=n;i++){
        hashArray[i]=(hashArray[i-1]*p+s[i-1])%m;
    }
    for(int i=0;i<n;i++){
        int runIdx=0;
        bool ok=true;
        while(runIdx<n){
            int len=min(i+1,n-runIdx);
            if(gethashArray(0,len-1)!=gethashArray(runIdx,runIdx+len-1)){
                ok=false;
                break;
            }
            runIdx+=len;
        }
        if(ok){
            cout<<i+1<<" ";
        }
    }
    return 0;
}