class Solution {
public:
    
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int n=h.size();
        vector<int> ps(n);
      vector<int> ns(n);
        // ps= previous smaller
        // ns=next smaller
        for(int i=0;i<n;i++){
            
            while(!s.empty() && h[s.top()]>=h[i]) {s.pop();}
            if(s.empty()){ps[i]=0;}
            else {ps[i]=s.top()+1;}
            
            s.push(i);
        }
        while (!s.empty())
        s.pop();
        
         for(int i=n-1;i>=0;i--){
            
            while(!s.empty() && h[s.top()]>=h[i]) s.pop();
            if(s.empty()){ns[i]=n;}
            else {ns[i]=s.top();}
             
            s.push(i);
        }
    //  for(int i=0;i<n;i++)  cout<<ps[i];
        
        int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, h[i] * (ns[i] - ps[i]));
      }
      return maxA;
        
        
    }
};