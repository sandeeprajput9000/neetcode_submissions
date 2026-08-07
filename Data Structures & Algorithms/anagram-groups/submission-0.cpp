class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> V;
        for(auto it : strs){
            string temp=it;
            sort(temp.begin(),temp.end());
            V[temp].push_back(it);
        }
        vector<vector<string>>result;
        for(auto [first,second] : V){
            result.push_back(second);
        }
        return result;
    }
};
