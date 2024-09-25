#include<bits/stdc++.h>
using namespace std;

void generateVector(vector<long long> &vec,long long n) {
    while (n!=1)
    {  vec.push_back(n);
       if((n&1)==0){
        n=(n>>1);
       }else{
        n=3*n+1;
       }
    }

    vec.push_back(n);
    return;
}
int main() {
    long long n;
    cin>>n;
    vector<long long> vec;
    generateVector(vec,n);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
    
}