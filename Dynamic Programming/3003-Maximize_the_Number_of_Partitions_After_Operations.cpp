class Solution {
public:
    int dfs(int i,int mask,bool has_changed,const string &s,int k,unordered_map<long long,int> &memo)
    {
        if(i==s.size())
        {
            return 1;
        }
        long long key=(long long)i<<32 | mask<<1 | has_changed;
        if(memo.count(key))
        {
            return memo[key];
        }
        int ans=0,next_mask=mask | (1<<(s[i]-'a'));
        if(__builtin_popcount(next_mask)>k)
        {
            ans=max(ans,1+dfs(i+1,1<<(s[i]-'a'),has_changed,s,k,memo));
        }
        else
        {
            ans=max(ans,dfs(i+1,next_mask,has_changed,s,k,memo));
        }
        if(!has_changed)
        {
            for(int x=0;x<26;x++)
            {
                next_mask=mask | (1<<x);
                if(__builtin_popcount(next_mask)>k)
                {
                    ans=max(ans,1+dfs(i+1,1<<x,true,s,k,memo));
                }
                else
                {
                    ans=max(ans,dfs(i+1,next_mask,true,s,k,memo));
                }
            }
        }
        return memo[key]=ans;
    }
    int maxPartitionsAfterOperations(string s,int k)
    {
        unordered_map<long long,int> memo;
        return dfs(0,0,false,s,k,memo);
    }
};
