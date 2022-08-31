string repeatString = dfs(s,i+1,len);
int j = 0;
string newString = "";
while(j < repeatTimes){
newString += repeatString;
j++;
}
totalString += newString;
}
else{
totalString += s[i];
}
i++;
}
return totalString;
}
public:
string decodeString(string s) {
int len = s.length();
string totalString = "";
for(i=0;i<len;i++){
if(s[i] == '[' || s[i] == ']'){
continue;
}
if(s[i] >= '0' && s[i] <= '9'){
// cout << i << endl;
string number = "";
while(s[i] >= '0' && s[i] <= '9'){
number += s[i];
i++;
}
int repeatTimes = stoi(number);
string repeatString = dfs(s,i+1,len);
int j = 0;
string newString = "";
while(j < repeatTimes){
newString += repeatString;
j++;
}
totalString += newString;
}
else{
totalString += s[i];
}
}
return totalString;
}
};
```