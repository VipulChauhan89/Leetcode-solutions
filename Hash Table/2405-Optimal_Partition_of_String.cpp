class Solution {
public:
    int partitionString(string s) 
    {
        int count=0;
        unordered_set<char> m;
        for(auto i:s)
        {
            if(m.find(i)!=m.end())
            {
                count++;
                m.clear();
            }
            m.insert(i);
        }
        return count+1;
    }
};
