class Solution {
public:


    string encode(vector<string>& strs) {
        string ans = "";

        for(string s : strs) {
            ans += to_string(s.size());
            ans += '#';
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        int n = s.size();

        while(i < n) {

           
            int j = i;

            while(s[j] != '#') {
                j++;
            }

           
            int len = stoi(s.substr(i, j - i));

           
            j++;

            
            string str = s.substr(j, len);
            ans.push_back(str);

           
            i = j + len;
        }

        return ans;
    }
};
