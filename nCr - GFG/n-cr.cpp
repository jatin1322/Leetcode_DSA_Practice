// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++



class Solution{
public:
    int nCr(int n, int r){
        // code here]
        int dp[n+1][n+1];
        if(n<r){
           return 0;
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<i+1; j++){
                if(j == 0 || i == j){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = ((dp[i-1][j-1])%1000000007+(dp[i-1][j])%1000000007)%1000000007;
                }
            }
        }
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends