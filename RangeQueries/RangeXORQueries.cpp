#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    int n;
    vector<long long> segTree;
    public:
    SegmentTree(int n){
        this->n=n;
        segTree.resize(4*n+2);
    }
    void buildSegmentTree(int arr[],int index,int low,int high){
        if(high==low){
            segTree[index]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        buildSegmentTree(arr,2*index+1,low,mid);
        buildSegmentTree(arr,2*index+2,mid+1,high);
        segTree[index]=segTree[2*index+1]^segTree[2*index+2];
    }

    long long query(int index,int low,int high,int l,int r){
        if(low>=l && high<=r){
            return segTree[index];
        }
        if(l>high || r<low || l>r){
            return 0;
        }
        int mid= low+(high-low)/2;
        long long left=query(2*index+1,low,mid,l,r);
        long long right= query(2*index+2,mid+1,high,l,r);
        return left^right;
    }
};

int main(){
  int n,q;
  cin>>n>>q;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  SegmentTree tree(n);
  tree.buildSegmentTree(arr,0,0,n-1);
  while(q--){
      int l,r;
      cin>>l>>r;
      cout<<tree.query(0,0,n-1,l-1,r-1)<<endl;
  }
  return 0;
}