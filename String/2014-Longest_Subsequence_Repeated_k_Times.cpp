class Solution {
public:
    bool isKTimes(string sub,string t,int k) 
    {
        int count=0,j=0;
        for(auto &i:t)
        {
            if(i==sub[j])
            {
                if(++j==sub.size())
                {
                    j=0;
                    if(++count==k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        queue<string> q;
        q.push("");
        while(!q.empty())
        {
            string current=q.front();
            q.pop();
            for(auto i='a';i<='z';i++)
            {
                string next=current+i;
                if(isKTimes(next,s,k))
                {
                    ans=next;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};