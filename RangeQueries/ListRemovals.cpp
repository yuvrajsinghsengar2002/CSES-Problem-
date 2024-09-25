#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int val;
    int numberOfNodes;
};
class SegmentTree{
    vector<treeNode> segtree;
    public:
    SegmentTree(int n){
        segtree.resize(4*n);
    }
    void buildSegmentTree(int index,int low,int high,int arr[]){
        if(low==high){
            segtree[index].numberOfNodes=1;
            segtree[index].val=arr[low];
            return ;
        }
        int mid=low+(high-low)/2;
        buildSegmentTree(2*index+1,low,mid,arr);
        buildSegmentTree(2*index+2,mid+1,high,arr);
        segtree[index].numberOfNodes=segtree[2*index+1].numberOfNodes+segtree[2*index+2].numberOfNodes;
    }

    int query(int index,int low, int right,int number){
        if(low==right){
            segtree[index].numberOfNodes=0;
            return segtree[index].val;
        }
        int mid=low+(right-low)/2;
        int ans;
        if(segtree[2*index+1].numberOfNodes>=number){
           ans=query(2*index+1,low,mid,number);
        }else{
           ans=query(2*index+2,mid+1,right,number-segtree[2*index+1].numberOfNodes);
        }
        segtree[index].numberOfNodes=segtree[2*index+1].numberOfNodes+segtree[2*index+2].numberOfNodes;
        return ans;
    }

};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SegmentTree tree(n);
    tree.buildSegmentTree(0,0,n-1,arr);
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        cout<<tree.query(0,0,n-1,q)<<endl;
    }
    
    
    return 0;
}