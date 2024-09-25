#include<bits/stdc++.h>
using namespace std;
int main(){
    set<long> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size();
}