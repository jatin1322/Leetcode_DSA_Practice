//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int ind,int n,vector<vector<int>> &dp,int *price){
        if(ind==0) return dp[ind][n]= n*price[0];
        if(dp[ind][n]!=-1) return dp[ind][n];
        int nottake=helper(ind-1,n,dp,price);
        int take=INT_MIN;
        int rod_length=ind+1;
        if(rod_length<=n){
            take=price[ind]+helper(ind,n-rod_length,dp,price);
        }
        return dp[ind][n]=max(take,nottake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        helper(n-1,n,dp,price);
        return dp[n-1][n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends