#include<iostream>
#include<stdio.h>
using namespace std;

int printArray(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int bubbleSort(int *a, int n)
{
    int temp;
    for(int i=0;i<n-1;i++) // For number of passes
    {
        for(int j=0; j<n-1-i; j++)  //For number of comparisons in each pass
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int arr[]={10,5,6,13,8,3};
    int size=6;
    printArray(arr,size);
    bubbleSort(arr,size);
    printArray(arr,size);
}

// #include<stdio.h>
 
// void printArray(int* A, int n){
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }
// void bubbleSort(int *A, int n){
//     int temp;
//     int isSorted = 0;
//     for (int i = 0; i < n-1; i++) // For number of pass
//     {
//         printf("Working on pass number %d\n", i+1); 
//         for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
//         {
//             if(A[j]>A[j+1]){
//                 temp = A[j];
//                 A[j] = A[j+1];
//                 A[j+1] = temp; 
//             }
//         }  
//     } 
// }
 
// void bubbleSortAdaptive(int *A, int n){
//     int temp;
//     int isSorted = 0;
//     for (int i = 0; i < n-1; i++) // For number of pass
//     {
//         printf("Working on pass number %d\n", i+1);
//         isSorted = 1;
//         for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
//         {
//             if(A[j]>A[j+1]){
//                 temp = A[j];
//                 A[j] = A[j+1];
//                 A[j+1] = temp;
//                 isSorted = 0;
//             }
//         } 
//         if(isSorted){
//             return;
//         }
//     } 
// }
 
// int main(){
//     // int A[] = {12, 54, 65, 7, 23, 9};
//     int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
//     // int A[] = {1, 2, 3, 4, 5, 6};
//     int n = 11;
//     printArray(A, n); // Printing the array before sorting
//     bubbleSort(A, n); // Function to sort the array
//     printArray(A, n); // Printing the array before sorting
//     return 0;
// }