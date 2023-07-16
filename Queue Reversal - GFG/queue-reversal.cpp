//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    void f(queue<int> &q){
        // base case
        if(q.empty()) return;
        
        int x=q.front();
        q.pop();
        f(q);
        q.push(x);
    }


    queue<int> rev(queue<int> q)
    {
        // add code here.
          f(q);
        return q;

       queue<int>ans;
        stack<int>stk;
        while(!q.empty()){
            stk.push(q.front());
            q.pop();
        }
        while(!stk.empty()){
            ans.push(stk.top());
            stk.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends