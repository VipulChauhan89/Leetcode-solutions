class Solution {
public:
    vector<int> findAnagrams(string s,string p) 
    {
        vector<int> ans;
        if (s.empty() || s.size()<p.size())
        {
            return ans;
        } 
        unordered_map<char,int> p_count;
        for(char c:p)
        {
            p_count[c]++;
        } 
        int left=0,right=0,count=p.size();
        while(right<s.size()) 
        {
            if(p_count[s[right++]]-- >=1)
            {
                count--;
            } 
            if(count==0)
            {
                ans.push_back(left);
            } 
            if(right-left==p.size() && p_count[s[left++]]++ >=0)
            {
                count++;
            } 
        }
        return ans;
    }
};
