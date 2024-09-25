#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int> segtree;
    public:
    SegmentTree(int n){
        segtree.assign(4*n+1,0);
    }
    void buildSegmentTree(int index,int low,int high,int arr[]){
        if(low==high){
            segtree[index]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        buildSegmentTree(2*index+1,low,mid,arr);
        buildSegmentTree(2*index+2,mid+1,high,arr);
        segtree[index]=max(segtree[2*index+1],segtree[2*index+2]);
    }
    
    int query(int index,int low,int high,int arr[],int val){
        if(low==high){
            if(segtree[index]<val){
                return 0;
            }
            segtree[index]-=val;
            return low+1;
        }
        int mid=low+(high-low)/2;

        if(segtree[2*index+1]>=val){
           int ans=query(2*index+1,low,mid,arr,val);
           segtree[index]=max(segtree[2*index+1],segtree[2*index+2]);
           return ans;
        }else if(segtree[2*index+2]>=val){
              int ans=query(2*index+2,mid+1,high,arr,val);
              segtree[index]=max(segtree[2*index+1],segtree[2*index+2]);
              return ans;
        }else{
            return 0;
        }
    }

};

int main(){
   int n,m;
   cin>>n>>m;
   int hotel[n];
   for(int i=0;i<n;i++){
      cin>>hotel[i];
   }
   SegmentTree seg(n);
   seg.buildSegmentTree(0,0,n-1,hotel);
   for(int i=0;i<m;i++){
       int r;
       cin>>r;
       cout<<seg.query(0,0,n-1,hotel,r)<<endl;
   }

   return 0;
}