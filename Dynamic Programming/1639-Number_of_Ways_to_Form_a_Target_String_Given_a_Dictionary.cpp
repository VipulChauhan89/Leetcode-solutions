class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<string> &words,string &target,vector<vector<long long>> &char_count,int i,int j,vector<vector<long long>> &memo)
    {
        if(j>=target.size())
        {
            return 1;
        }
        if(i>=words[0].size())
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        long long inc=0,exc=0;
        if(char_count[i][target[j]-'a'])
        {
            inc=((char_count[i][target[j]-'a'])*(solve(words,target,char_count,i+1,j+1,memo)))%mod;
        }
        exc=solve(words,target,char_count,i+1,j,memo);
        return memo[i][j]=(inc+exc)%mod;
    }
    int numWays(vector<string>& words, string target) 
    {
        int word_count=words.size(),word_len=words[0].size();
        vector<vector<long long>> char_count(word_len,vector<long long>(26));
        for(string &s:words)
        {
            for(int i=0;i<word_len;i++)
            {
                char_count[i][s[i]-'a']++;
            }
        }
        vector<vector<long long>> memo(word_len+1,vector<long long>(target.size()+1,-1));
        return solve(words,target,char_count,0,0,memo);
    }
};
