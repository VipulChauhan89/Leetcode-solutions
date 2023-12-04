class Solution {
public:
    string largestGoodInteger(string num) 
    {
        int ans=-1;
        for(int i=2;i<num.length();i++)
        {
            if(num[i-2]==num[i-1] && num[i-1]==num[i])
            {
                ans=max(ans,num[i-2]-'0');
            }
        }
        return (ans==-1)?"":string(3,'0'+ans);
    }
};
