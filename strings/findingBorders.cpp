#include<bits/stdc++.h>

using namespace std;
vector<long> power;
int mod=1e9+7;
int p=31;
int main(){
  string s;
  cin>>s;
  int n=s.length();
  power.resize(n-1,1);
  for(int i=1;i<n-1;i++){
    power[i]=(power[i-1]*p)%mod;
  }
  long ph=0;
  long sh=0;
  for(int i=0;i<n-1;i++){
    int l=s[i]-'a'+1;
    int r=s[n-i-1]-'a'+1;
    ph=(ph+(l*power[i]))%mod;
    sh=(sh*p + r)%mod;
    if(ph==sh){
      cout<<i+1<<" ";
    }
  }

  return 0;
}