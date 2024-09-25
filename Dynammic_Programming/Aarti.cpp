#include<bits/stdc++.h>
using namespace std;
bool isPossible(int x,vector<int> &arr,int max_move){
    int moves=0;
    for(int i=0;i<arr.size();i++){
        moves=moves+ ceil(arr[i]/x);
    }
    return moves<=max_move;
}
int getMinDecrement(vector<int> arr,int max_move){
    int left=1;
    int right=-1;
    for(int i=0;i<arr.size();i++)
    {
       right=max(right,arr[i]);
    }
    int ans=-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(isPossible(mid,arr,max_move)){
          ans=mid;
          right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return ans;
}

int main(){
      vector<int> arr ={1,2,3};
      int max_move=4;
      cout<<getMinDecrement(arr,max_move);
}