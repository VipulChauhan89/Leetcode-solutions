class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_map<char,vector<int>> m;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].push_back(i);
        }
        for(auto &i:m)
        {
            vector<int> &ind=i.second;
            int st=ind[0],e=ind[ind.size()-1];
            if(e-st<=1)
            {
                continue;
            }
            unordered_set<char> mid;
            for(int j=st+1;j<e;j++)
            {
                mid.insert(s[j]);
            }
            ans+=mid.size();
        }
        return ans;
    }
};
