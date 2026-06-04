class Solution {
public:
    int waviness(int x)
    {
        string s=to_string(x);
        int count=0;
        for(int i=1;i<s.size()-1;i++)
        {
            if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i] < s[i+1]))
            {
                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1,int num2)
    {
        long long ans=0;
        for(int x=num1;x<=num2;x++)
        {
            ans+=waviness(x);
        }
        return ans;
    }
};
