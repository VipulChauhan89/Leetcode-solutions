class Solution {
public:
    bool hasAllCodes(string s,int k)
    {
        unordered_set<string> seen;
        int target=1<<k;
        for(int i=0;i<=(int)s.size()-k;i++)
        {
            seen.insert(s.substr(i,k));
            if((int)seen.size()==target)
            {
                return true;
            }
        }
        return (int)seen.size()==target;
    }
};
