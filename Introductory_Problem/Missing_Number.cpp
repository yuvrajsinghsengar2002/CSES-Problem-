#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    sum=1;
    for(int i=0;i<n-1;i++)
    {   sum=sum^(i+2);
        sum=sum^arr[i];
    }
    cout<<sum;
    return 0;
}