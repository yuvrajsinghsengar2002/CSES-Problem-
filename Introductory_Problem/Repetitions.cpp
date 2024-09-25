#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=1;
    int count=1;
    for(int i=1;i<s.length();i++){
        if(s[i-1]==s[i]){
            count++;
        }else{
            count=1;
        }
        ans=max(ans,count);
    }
    cout<<ans<<endl;
}