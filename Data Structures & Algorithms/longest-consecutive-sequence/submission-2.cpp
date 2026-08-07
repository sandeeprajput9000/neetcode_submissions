class Solution {
public:

// APPROACH 1

    // int longestConsecutive(vector<int>& nums) {
    //     int maxi=INT_MIN;
    //     int n=nums.size();
        // if(n==0) return 0;
        // unordered_map<int,int>mp;
        // for(int i=0;i<n;i++)
        //   mp[nums[i]]++;

    //     for(int i=0;i<n;i++){
    //         if(mp.find(nums[i]-1) == mp.end()) continue;
    //         int temp=nums[i];
    //         int cnt=1;
    //         while(mp.find(temp+1)!=mp.end()){
    //             cnt++;
    //             temp=temp+1;
    //         }
    //         maxi=max(maxi,cnt);
    //     }
    //     return maxi;
    // }


     int longestConsecutive(vector<int>& nums) {
            vector<int>start;
            int maxi=INT_MIN;
            int n=nums.size();
            if(n==0) return 0;
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++)
               mp[nums[i]]++;

             for(int i=0;i<nums.size();i++){
                if(mp.find(nums[i]-1)==mp.end()){
                    start.push_back(nums[i]);
                }
             }
             for(int i=0;i<start.size();i++){
                int temp=start[i];
                int cnt=1;
                while(mp.find(temp+1)!=mp.end()){
                    cnt++;
                    temp=temp+1;
                }
                maxi=max(maxi,cnt);
             }
             return maxi;
     }
};
