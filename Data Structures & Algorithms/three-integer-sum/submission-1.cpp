class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0;
         vector<vector<int>>result;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1])
                       continue;

            int target1=target-nums[i];
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r];

                if(sum==target1){
                   vector<int>temp(3,0);
                   temp[0]=nums[i];
                   temp[1]=nums[l];
                   temp[2]=nums[r];
                   result.push_back(temp);
                   l++;
                   r--;

                     while (l < r && nums[l] == nums[l - 1])
                           l++;

                    while (l < r && nums[r] == nums[r + 1])
                            r--;

                }else if(sum<target1){
                    l++;
                }else{
                    r--;
                }
               
            }
            
        }
        return result;
    }
};
