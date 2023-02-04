class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n1=s1.size(),n2=s2.size();
        vector<int> ct(26,0);
        for(auto i:s1)
        {
            ct[i-'a']++;
        }
        for(int i=0;i<n2-n1+1;i++)
        {
            vector<int> ct2(26,0);
            for(int j=i;j<i+n1;j++)
            {
                ct2[s2[j]-'a']++;
            }
            if(ct==ct2)
            {
                return true;
            }
        }
        return false;
    }
};
