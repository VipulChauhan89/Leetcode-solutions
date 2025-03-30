class Solution {
public:
    bool isValid(int start,int end,string &s,unordered_map<char,int> &m)
    {
        for(int i=start;i<=end;i++)
        {
            if(m[s[i]]!=0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> m;
        vector<int> ans;
        int n=s.size(),prev=0;
        for(auto &i:s)
        {
            m[i]++;
        }
        for(int i=0;i<n;i++)
        {
            m[s[i]]--;
            if(isValid(prev,i,s,m))
            {
                ans.push_back(i-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};
