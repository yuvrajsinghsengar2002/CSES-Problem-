#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int apartment[m];
  for(int i=0;i<m;i++){
    cin>>apartment[i];
  }
  sort(apartment,apartment+m);
  int i=0,j=0;
  int ans=0;
  while(i<n && j<m){
    if(abs(arr[i]-apartment[j])<=k){
        ans++;
        i++;
        j++;
    }else if(arr[i]<(apartment[j]-k)){
        i++;
    }
    else{
        j++;
    }
  }

  cout<<ans;
  return 0;
}
