class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>f1(26,0);
        vector<int>f2(26,0);

        int l=0,r=0;
        int n=s2.size();
        for(char ch : s1){
            f1[ch-'a']++;
        }
        while(r<n){
            f2[s2[r]-'a']++;

            while(r-l+1 > s1.size()){
                f2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==s1.size() && f1==f2) 
               return true;

            r++;   
        }
        return false;
    }
};
