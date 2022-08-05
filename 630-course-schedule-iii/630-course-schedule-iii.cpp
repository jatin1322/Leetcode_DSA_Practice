class Solution {
public:
  static  bool comp(vector<int> &a,vector<int> &b){
        return (a[1]<b[1]);
    }
    int scheduleCourse(vector<vector<int>>& c) {
          sort(c.begin(),c.end(),comp);
        priority_queue<int> pq;
        int day=0;
        int n=c.size();
        for(int i=0;i<n;i++){
        if(c[i][0]<=c[i][1])
        {  if(c[i][0]+day<=c[i][1]){
            pq.push(c[i][0]);
                day+=c[i][0];
            }
        else{
                int m=pq.top();
                if(m>c[i][0]){
                   pq.pop();
                    pq.push(c[i][0]);
                    day+=c[i][0];
                    day-=m;
                }
            }
        
        }
        }
       
        
         return pq.size();
    }
};