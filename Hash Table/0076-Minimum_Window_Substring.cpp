class Solution {
public:
    string minWindow(string s,string t) 
    {
        int sn=s.size(),tn=t.size(),left=0,count=0,mnL=INT_MAX,mnLeft=0;
        vector<int> m(64,0),temp(64,0);
        for(auto i:t)
        {
            temp[0x3f & i]++;
        }
        for(int i=0;i<sn;i++)
        {
            int idx=0x3f & s[i];
            if(temp[idx]==0)
            {
                continue;
            }
            m[idx]++;
            if(m[idx]<=temp[idx])
            {
                count++;
            }
            if(count==tn)
            {
                while(temp[0x3f & s[left]]==0 || m[0x3f & s[left]]>temp[0x3f & s[left]])
                {
                    if(m[0x3f & s[left]]!=0)
                    {
                        m[0x3f & s[left]]--;
                    }
                    left++;
                }
                if(i-left+1<mnL)
                {
                    mnL=i-left+1;
                    mnLeft=left;
                }
            }
        }
        return ((mnL==INT_MAX)?"":s.substr(mnLeft,mnL));
    }
};
