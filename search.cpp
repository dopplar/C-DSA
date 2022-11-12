#include<iostream>
using namespace std;

int linearsearch(int a[], int n, int s)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
        cout<<"Element position is: "<<i+1;
    }
    return 0;
}

int binarysearch(int a[],int n, int s)
{
    int low,mid,high;
    low=0;
    high=n-1;
    mid=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==s)
        {
            cout<<"Element found at position: "<<mid+1;
        }
        if(a[mid]<s)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return 0;
}

int main()
{
    int n,s;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements into the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to be searched"<<endl;
    cin>>s;
    binarysearch(arr,n,s);
    //linearsearch(arr,n,s);
    return 0;
}