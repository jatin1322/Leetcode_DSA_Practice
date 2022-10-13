//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int l1=m-l+1;
         int l2=r-m;
         int brr[l1];
         int crr[l2];
         for(int i=0;i<l1;i++){
             brr[i]=arr[l+i];
         }
         for(int i=0;i<l2;i++){
             crr[i]=arr[m+1+i];
         }
         int i=0;
         int j=0;
         int k=l;
         while(i<l1 && j<l2){
             if(brr[i]<=crr[j]){
                 arr[k]=brr[i];
                 i++;
                 k++;
             }
             else{
                 arr[k]=crr[j];
                j++;
                k++;
                
             }
         }
         while(i<l1){
             arr[k]=brr[i];
             k++;
             i++;
         }
         while(j<l2){
             arr[k]=crr[j];
             k++;
             j++;
         }
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l<r){
        int mid=(r+l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        }
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends