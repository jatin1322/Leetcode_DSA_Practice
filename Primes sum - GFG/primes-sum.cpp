// { Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
    
  public:
  bool isprime(int n){
     for(int i=2;i*i<=n;i++){
         if(n%i==0)
           return false;
     }
     return true;
 }

    string isSumOfTwo(int N){
        if(N%2==1){
           if(isprime(N-2)){
               return "Yes";
           } 
           else{
               return "No";
           }
        }
        else{
            if(N==4){
                return "Yes";
            }
            else{
                for(int i=3; i<N ; i+=2){
                    if(isprime(i) && isprime(N-i) ){
                       return "Yes";  
                    }
                }
                 return "No";
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
  // } Driver Code Ends