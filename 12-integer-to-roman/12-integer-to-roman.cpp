class Solution {
public:
    string intToRoman(int nums) {
   /*      if(nums==0) return "";
        if(nums==1) return "I";
          if(nums==5) return "V";
          if(nums==10) return "X";
          if(nums==50) return "L";
          if(nums==100) return "C";
          if(nums==500) return "D";
         if(nums==1000) return "M";
        
        if(nums<=3){
            string s="";
            for(int i=0; i<nums; i++){
                s+="I";
            }
            return s;
        }
        if(nums==4){
            return "IV";
        }
         if(nums<=8){
            string s="V";
            for(int i=0; i<nums-5; i++){
                s+="I";
            }
            return s;
        }
         if(nums==9){
            return "IX";
        }
        if(nums<40){
          int a=nums/10;
            string s="";
            for(int i=0; i<a; i++){
                s+="X";
            } 
            return s+intToRoman(nums%10);
        }
        if(nums==40){
            return "XL";
        }
        if(nums<50){
            return intToRoman(40)+intToRoman(nums-40);
        }
        if(nums<=89){
            return intToRoman(50)+intToRoman(nums-50);
        }
        if(nums==90){
            return "XC";
        }
          if(nums<100){
            return intToRoman(90)+intToRoman(nums-90);
        }
         if(nums<400){
          int a=nums/100;
            string s="";
            for(int i=0; i<a; i++){
                s+="C";
            } 
            return s+intToRoman(nums%100);
        }
        if(nums==400){
            return "CD";
        }
        if(nums<500){
            return intToRoman(400)+intToRoman(nums-400);
        }
         if(nums<900){
            return intToRoman(500)+intToRoman(nums-500);
        }
        if(nums==900) return "CM";
        if(nums<=999) return intToRoman(900)+intToRoman(nums-900);
        if(nums<=3999) {
            int a=nums/1000;
            string s="";
            for(int i=0; i<a; i++){
                s+="M";
            } 
            return s+intToRoman(nums%1000);
        } 
      return "-1";   */
              int intCode[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string stringCode[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res="";
        for(int i=0;i<13;i++)
        {
            while(nums>=intCode[i])
            {
                res+=stringCode[i];
                nums-=intCode[i];
            }
        }
        
        return res;
    }
};