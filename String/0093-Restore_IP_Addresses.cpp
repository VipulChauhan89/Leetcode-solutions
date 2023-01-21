class Solution {
public:
    bool valid(string s)
    {
        int n=s.size();
        return ((n && stol(s)>255) || (n>3 || n==0) || (n>1 && s[0]=='0'))?false:true;
    }
    void back(string s,string temp,vector<string> &ans,int i,int dot)
    {
        if(dot==3)
        {
            if(valid(s.substr(i)))
            {
                ans.push_back(temp+s.substr(i));
            }
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(valid(s.substr(i,j-i+1)))
            {
                temp.push_back(s[j]);
                temp.push_back('.');
                back(s,temp,ans,j+1,dot+1);
                temp.pop_back();
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> ans;
        if(s.size()<4)
        {
            return ans;
        }
        back(s,"",ans,0,0);
        return ans;
    }
};
