class Solution {
public:
    vector<string> divideString(string s,int k,char fill)
    {
        vector<string> ans;
        int n=s.length();
        for(int i=0;i<n;i+=k)
        {
            string ss=s.substr(i,k);
            if(ss.length()!=k)
            {
                ss+=string(k-ss.length(),fill);
                
            }
            ans.push_back(ss);
        }
        return ans;
    }
};
