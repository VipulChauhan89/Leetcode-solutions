class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> f1(10,0);
        string s1=to_string(n);
        for(auto &i:s1)
        {
           f1[i-'0']++;
        }
        for(int i=0;i<=31;i++)
        {
            int num=(1<<i);
            vector<int> f2(10,0);
            string s2=to_string(num);
            if(s1.length()!=s2.length())
            {
                continue;
            }
            for(auto &j:s2)
            {
                f2[j-'0']++;
            }
            if(f1==f2)
            {
                return true;
            }
        }
        return false;
    }
};
