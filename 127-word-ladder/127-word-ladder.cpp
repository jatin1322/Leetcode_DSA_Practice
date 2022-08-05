class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& dic) {
        set<string> st,words;
        for(auto it:dic){
            words.insert(it);
        }
        queue<string> q;
        st.insert(bw);
        q.push(bw);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            ans++;
            for(int i=0;i<n;i++){
            string s=q.front();
            q.pop();
                if(s==ew)return ans;
                
                string t;
                
                for(int i=0;i<s.size();i++){
                    t=s;
                    for(char c='a';c<='z';c++){
                        t[i]=c;
                        if(words.count(t) && !st.count(t)){
                            q.push(t);
                            st.insert(t);
                        }
                    }
                }
                    
            }
        }
        return 0;
    }
};