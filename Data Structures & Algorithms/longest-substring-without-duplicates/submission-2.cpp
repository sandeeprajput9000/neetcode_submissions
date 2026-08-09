class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(255,0);
        int maxi=INT_MIN;
        int n=s.size();
        if(s.empty()) return 0;
        int l=0,r=0;
        while(r<n){
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;

            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi==INT_MIN ? 0 : maxi;

    }
};
