class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>S(26,0);
        vector<char>T(26,0);
        
        for(int i=0;i<s.size();i++){
            S[s[i]-'a']++;
        }
         for(int i=0;i<t.size();i++){
            T[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(S[i]!=T[i])
             return false;
        }
        return true;
    }
};
