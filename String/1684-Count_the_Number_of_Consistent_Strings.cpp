class Solution {
public:
    int countConsistentStrings(string allowed,vector<string> &words) 
    {
        int ans=0;
        set<char> s1;
        for(auto i:allowed)
        {
            s1.insert(i);
        }
        for(auto &i:words)
        {
            bool check=true;
            for(auto j:i)
            {
                if(s1.count(j)==0)
                {
                    check=false;
                    break;
                }
            }
            ans+=(check?1:0);
        }
        return ans;
    }
};
