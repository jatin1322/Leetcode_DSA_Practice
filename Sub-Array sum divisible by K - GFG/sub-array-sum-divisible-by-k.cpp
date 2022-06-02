// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long subCount(long long v[], int n, long long k)
	{
	    
        long long ans=0;
        map<long long,long long> m;
        m[0]++;
        for(long long i=0; i<n; i++){
            ans=ans+v[i];
            long long a=ans%k;
            if(a<0) a=a+k;
            m[a]++;
            
        }
        long long ans1=0;
        for(auto x:m){
            long long c=x.second;
            
           if(c>1) {ans1=ans1+(c*(c-1))/2;}
        }
        return ans1;
	}



};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends