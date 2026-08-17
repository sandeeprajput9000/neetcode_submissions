class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int>mp;
        int maxi=INT_MIN;
        int result=INT_MIN;
        while(r<n){
            mp[s[r]]++;
            maxi=max(maxi,mp[s[r]]);

            while((r-l+1)-maxi > k){
                mp[s[l]]--;
                maxi=max(maxi,mp[s[l]]);
                l++;
            }

            result=max(result,r-l+1);
            r++;

        }
        return result;
    }
};
