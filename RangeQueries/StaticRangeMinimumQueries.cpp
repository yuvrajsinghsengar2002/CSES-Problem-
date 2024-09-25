#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int> segTree;
    int n;
    public:
    SegmentTree(int n){
        this->n=n;
        segTree.resize(4*n+2);
    }

    void buildSegmentTree(int arr[],int index,int low,int high){
        if(low==high){
            segTree[index]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        buildSegmentTree(arr,2*index+1,low,mid);
        buildSegmentTree(arr,2*index+2,mid+1,high);
        segTree[index]=min(segTree[2*index+1],segTree[2*index+2]);
        
    }

    int query(int index,int low,int high,int l,int r){
        if(low>=l && high<=r){
            return segTree[index];
        }
        if(low>r || high<l){
            return INT_MAX;
        }
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right= query(2*index+2,mid+1,high,l,r);
        return min(left,right);
  
    };

};

int main(){
     int n,q;
     cin>>n>>q;
     int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     SegmentTree st(n);
     st.buildSegmentTree(arr,0,0,n-1);
     while(q--){
         int l,r;
         cin>>l>>r;
         cout<<st.query(0,0,n-1,l-1,r-1)<<endl;
     }
     return 0;
}