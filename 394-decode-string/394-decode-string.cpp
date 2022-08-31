
  class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;
        int i = 0;
        while(i<n){
            // if we encounter a digit
            if(s[i] >= '0' && s[i] <= '9'){
                string num = "";
                // make the largest possible digit
                while(s[i] >= '0' && s[i] <= '9' && i < n){
                    num += s[i++];
                }
                // push to stack
                st.push(num);
                continue;
            }
            // if we encounter a letter
            else if(s[i] >= 'a' && s[i] <= 'z'){
                string word = "";
                // make the largest possible string
                while(s[i] >= 'a' && s[i] <= 'z' && i < n){
                    word += s[i++];
                }
                // push to stack
                st.push(word);
                continue;
            }
            // if we encounter a closing bracket
            else if(s[i] == ']'){
                string word = "";
                string tp;
                // form the largest possible string possible until we encounter a 
                // digit string
                while(!st.empty()){
                    tp = st.top();
                    st.pop();
                    if(tp[0] >= 'a' && tp[0] <= 'z'){
                        word = tp + word;
                    }
                    else break;
                }
                int x = stoi(tp);
                string present = "";
                // multiply the string by the number present before it
                while(x--){
                    present += word;
                }
                // push the string back to stack
                st.push(present);
            }
            i++;
        }
        string ans = "";
        // take out the strings from the stack
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

