class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        bool flag=1;
        int i;
        for(i=n-1;i>=0;i--){
            if( num[i]-'0' & 1){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return "";
        }
        int len=i+1;
        return num.substr(0,len);
    }
};