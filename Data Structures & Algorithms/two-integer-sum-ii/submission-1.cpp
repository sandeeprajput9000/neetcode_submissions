class Solution {
public:
    vector<int> twoSum(vector<int>& number, int target) {
        int n=number.size();
        int i=0,j=n-1;
        while(i<j){
            int sum=number[i]+number[j];
            if(sum==target){
                return {i+1,j+1};
            }if(sum<target)
              i++;
            else
             j--;  
        }
        return {};
    }
};
