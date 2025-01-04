class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int n=s.length();
        unordered_set<string> ans;
        unordered_set<char> left;
        unordered_map<char,int> right;
        for(int i=0;i<n;i++)
        {
            right[s[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            right[s[i]]--;
            for(auto &j:left)
            {
                if(right[j]>0)
                {
                    ans.insert(string(1,s[i])+j);
                }
            }
            left.insert(s[i]);
        }
        return ans.size();
    }
};
