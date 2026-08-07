class Solution {
public:
//APPROACH 1

    // vector<int> topKFrequent(vector<int>& nums, int k) {

    //     unordered_map<int,int> mp;
    //     int n = nums.size();

    //     for(int i = 0; i < n; i++){
    //         mp[nums[i]]++;
    //     }

    //     priority_queue<pair<int,int>,
    //                    vector<pair<int,int>>,
    //                    greater<pair<int,int>>> pq;

    //     for(auto it : mp){

    //         if(pq.size() < k){
    //             pq.push({it.second, it.first});
    //         }
    //         else if(pq.top().first < it.second){
    //             pq.pop();
    //             pq.push({it.second, it.first});
    //         }
    //     }

    //     vector<int> V;

    //     while(!pq.empty()){
    //         V.push_back(pq.top().second);
    //         pq.pop();
    //     }

    //     return V;
    // }


    //APPROACH 2
     vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

       
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto it : mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        for(int freq = nums.size(); freq >= 1 && ans.size() < k; freq--){

            for(int num : bucket[freq]){
                ans.push_back(num);

                if(ans.size() == k)
                    break;
            }
        }

        return ans;
     }
};