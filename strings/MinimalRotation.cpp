#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string concatinated = s + s;
    vector<int> preSum(concatinated.length(),0);
    preSum[0]=concatinated[0]-'a';
    for(int i=1;i<concatinated.length();i++){
        preSum[i]=preSum[i-1]+(concatinated[i]-'a');
    }
    int startInd=-1;
    int ans = INT_MAX;
    for(int i=0;i<s.length();i++){
        int val = preSum[i+s.length()-1]-preSum[i]+(concatinated[i]-'0');
        if(val<ans){
            startInd=i;
        }

    }
    string answer = s.substr(startInd,s.length());
    cout<<answer<<endl;
    return 0;
}