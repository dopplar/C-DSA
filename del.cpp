#include<iostream>
using namespace std;

int del(int a[], int n, int ind)
{
    for(int i=ind; i<n; i++)
    {
        a[i]=a[i+1];
    }
    return 0;
}



int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    int ind=3;
    del(arr,size,ind);
    for(int i=0;i<size-1;i++)
    {
        cout<<arr[i]<<" ";
    }

}