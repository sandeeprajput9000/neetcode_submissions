class Solution {
public:

    // string encode(vector<string>& strs) {
    //      string str="";
    //      for(int i=0;i<strs.size();i++){
    //         str+=strs[i];
    //         str+='#';
    //      }
    //      return str;
    // }

    // vector<string> decode(string s) {
    //     vector<string>str;
    //      int i=0;
    //      int n=s.size();
    //       while(i < n) {

    //         int j = i;

    //         while(j < n && s[j] != '#') {
    //             j++;
    //         }

    //         string temp = s.substr(i, j - i);
    //         str.push_back(temp);

    //         i = j + 1;
    //     }
    //      return str;
    // }
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
