class Solution {
public:
    bool solve(string s1,string s2,unordered_map<string,bool> &dp) 
    {
        if(s1==s2)
        {
            return true;
        } 
        if(dp.find(s1+s2)!=dp.end())
        {
            return dp[s1+s2];
        } 
        int n=s1.size();
        bool sub_check=false;

        for(int i=1;i<n;i++) 
        {
            bool swap=(solve(s1.substr(0,i),s2.substr(n-i,i),dp) && solve(s1.substr(i,n-i),s2.substr(0,n-i),dp));
            bool not_swap=(solve(s1.substr(0,i),s2.substr(0,i),dp) && solve(s1.substr(i,n),s2.substr(i,n),dp));
            if(swap || not_swap) 
            {
                sub_check=true;
                break;
            }
        }
        return dp[s1+s2]=sub_check;
    }
    
    bool isScramble(string s1, string s2) 
    {
        if(s1.size()!=s2.size())
        {
            return false;
        } 
        if(s1=="" && s2=="")
        {
            return true;
        }
        unordered_map<string,bool> dp;
        return solve(s1,s2,dp);
    }
};
