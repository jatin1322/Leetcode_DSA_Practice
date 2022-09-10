// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string ans="";
//         int left=0;
//         int right=0;
//         int n=s.size();
//         int i=0;
//         string temp="";
//         while(i<n){
//             if(left==0 && right ==0 && s[i]=='('){
//                 left++;
//             }
//             else if(s[i]=='(') {left++; temp+='(';}
//             else if(s[i]==')'){ right++;  temp+=')';}
            
//             if(left==right){
                
//                 temp.pop_back();
//                 ans+=temp;
//                 temp="";
//                 right=0;
//                 left=0;
//             }
//             i++;
//         }
//         return ans;
//     }
    class Solution {
public:
    string removeOuterParentheses(string S) {
        int count = 0;
        std::string str;
        for (char c : S) {
            if (c == '(') {
                if (count++) {
                    str += '(';
                }
            } else {
                if (--count) {
                    str += ')';
                }
            }
        }
        return str;
    }
};

// };