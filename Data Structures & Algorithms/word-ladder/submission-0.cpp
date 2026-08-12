class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          unordered_set<string> wordSet(wordList.begin(), wordList.end());
       queue<pair<string,int>>q;
       q.push({beginWord,1});
       wordSet.erase(beginWord);

       while(!q.empty()){
         string word= q.front().first;
         int length=q.front().second;
         q.pop();

         if(word==endWord) return length;

         for(int i=0;i<word.size();i++){
            char orignal=word[i];
            for(char ch ='a';ch<='z';ch++){
                word[i]=ch;
                if(wordSet.find(word)!=wordSet.end()){
                    wordSet.erase(word);
                    q.push({word,length+1});
                }
            }
            word[i]=orignal; 
         }
       }
       return 0;
    }
};
