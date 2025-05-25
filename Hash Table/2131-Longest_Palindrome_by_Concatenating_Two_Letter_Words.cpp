class Solution {
public:
    int longestPalindrome(vector<string> &words) 
    {
        unordered_map<string,int> m;
        int count=0,aP=0;
        for(auto &i:words)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            string s=i.first;
            reverse(s.begin(),s.end());
            if(i.first==s)
            {
                count+=(i.second/2)*4;
                if(i.second%2==1)
                {
                    aP=1;
                }
            }
            else if(i.first<s && m.count(s))
            {
                count+=min(i.second,m[s])*4;
            }
        }
        return count+aP*2;
    }
};
