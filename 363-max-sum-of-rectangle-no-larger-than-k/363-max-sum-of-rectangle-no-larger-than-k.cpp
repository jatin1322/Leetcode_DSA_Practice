class Solution {
public:
 
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
             int ans2=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        int max_sum=INT_MIN;
        for(int j=0;j<n;j++){
            vector<int> temp(m,0);
            for(int i=j;i<n;i++){
                for(int k=0;k<m;k++){
                    temp[k]+=mat[i][k];
                }
                set<int> st;
                int curr_sum = 0;
                st.insert(0);
                for(int val: temp){
                    curr_sum+=val;
                    auto it = st.lower_bound(curr_sum - k);
                    if(it != st.end())
                        max_sum = max(max_sum, curr_sum - *it);
                    st.insert(curr_sum);
                }

                
                
            }
        }
        
        return max_sum;
    }
};