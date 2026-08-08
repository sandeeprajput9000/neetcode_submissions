class Solution {
public:
    bool isPalindrome(string s) {
       
        int n=s.size();
        if(s.empty()) return true;
         string result="";
         for(int i=0;i<n;i++){
            if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9')){
                result+=tolower(s[i]);
            }
         }
        
         int i=0,j=result.size()-1;
         while(i<j){
            if(result[i]!=result[j])
               return false;
            i++;
            j--;   
         }
       
        return true;
    }
};
