#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> A(n+1);
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    A[0]=0;
    for(int i=2;i<=n;i++){
        A[i]=A[i-1]+A[i];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<A[r]-A[l-1]<<endl;
    }
    return 0;

}