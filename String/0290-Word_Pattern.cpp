class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        string s1;
        unordered_map<char,string>m1;
        unordered_map<string,bool>m2;
        vector<string>st;
        stringstream ss(s);
        int count=0;
        while(ss>>s1)
        {
            count++;
            st.push_back(s1);
        }
        if(pattern.size()!=count)
        {
            return false;
        }
        else
        {
            for(int i=0;i<pattern.size();i++)
            {
                if(m1[pattern[i]]=="" && m2[st[i]]==true)
                {
                    return false;
                }
                else if(m1[pattern[i]]=="")
                {
                    m1[pattern[i]]=st[i];
                    m2[st[i]]=true;
                }
                else
                {
                    if(m1[pattern[i]]!=st[i]) 
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
