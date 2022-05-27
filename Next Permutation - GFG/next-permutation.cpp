// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
       int i,j;
        for( i=n-1;i>=1; i--){
          
            if(a[i-1]<a[i]){
             for( j=n-1; j>=0; j-- ){
                 if(a[j]>a[i-1]){
                     swap(a[j],a[i-1]);
                     sort(a.begin()+i,a.end());
                 return a; 
                     
                 }
               
             }
             
               
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends