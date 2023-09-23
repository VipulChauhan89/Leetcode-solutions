class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        unordered_map<string,int> dp;
        int max_chain=0;
        for(const auto &word:words) 
        {
            dp[word]=1;
            for(int i=0;i<word.size();i++) 
            {
                string prev_word=word.substr(0,i)+word.substr(i+1);
                if(dp.find(prev_word)!=dp.end()) 
                {
                    dp[word]=max(dp[word],dp[prev_word]+1);
                }
            }
            max_chain=max(max_chain,dp[word]);
        }
        return max_chain;
    }
};
