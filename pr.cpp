#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int findsq(int s, int e, int n)
{
    int i=0,count=0;
    while(i<e/2)
    {
        for (int j=s;j<=e;j++)
        if ((i*i)==j)
        count++;
    }   i++;
    return count; 
}

int main()
{
    int n=0;
    cin>>n;
    int res[n];
    int arr[n*2];
    for(int i=0,j=0;i<n;i+=2,j++)
    {
        cin>>arr[i]>>arr[i+1];
        res[j]=findsq(arr[i],arr[i+1],n);
    }
    for(int i=0;i<n;i++)
    cout<<res[i]<<endl;
}