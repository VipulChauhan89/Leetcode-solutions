class Solution {
public:
    bool canReach(string s,int minJump,int maxJump)
    {
        int n=s.length();
        if(s.back() & 1)
        {
            return false;
        }
        s[0]='v';
        int ans=0,maxR=maxJump;
        for(int i=minJump;i<n;i++)
        {
            if(i>maxR)
            {
                return false;
            }
            ans+=s[i-minJump]=='v';
            ans-=(i>maxJump) && s[i-maxJump-1]=='v';
            if(ans && (~s[i] & 1))
            {
                s[i]='v';
                maxR=i+maxJump;
            }
        }
        return ans;
    }
};
