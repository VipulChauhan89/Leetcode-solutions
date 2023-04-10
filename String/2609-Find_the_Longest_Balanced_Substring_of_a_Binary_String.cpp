class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n=s.length(),count1=0,count2=0,maxLen=0;
        for(int i=0;i<n;i++) 
        {
            if(s[i]=='0') 
            {
                if(count2!=0)
                {
                    count2=0;
                    count1=0;
                }
                count1++;
            } 
            else
            {
                count2++;
            }
            maxLen=max(maxLen,2*min(count1,count2));
        }
        return maxLen;    
    }
};
